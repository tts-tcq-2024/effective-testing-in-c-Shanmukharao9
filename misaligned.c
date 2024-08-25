#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
    int capturedColorCode;
    const char* capturedMajorColor;
    const char* capturedMinorColor;
} colorCodeManualItem;

colorCodeManualItem capturedManualList[25];

void printColorCodeManualOnConsole(int colorCode, const char* majorColor,const char* minorColor){
   printf("%d | %s | %s\n", colorCode, majorColor, minorColor);
}

int printColorMap(void (*manualPrinter)(int colorCode, const char* majorColor, const char* minorColor)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            manualPrinter(i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

void fakeManualPrinterStub(int colorCode, const char* majorColor, const char* minorColor) {
    (void)colorCode;
    (void)majorColor;
    (void)minorColor;
    // No logic needed for the stub, just a placeholder
}

void fakeManualPrinterMock(int colorCode, const char* majorColor, const char* minorColor) {
    colorCodeManualItem item = {colorCode, majorColor, minorColor};
    capturedManualList[colorCode] = item;
}

void test_cases(){
    //Value-based Testing
    int result = printColorMap(&fakeManualPrinterMock);
    assert(result == 25);
    assert(result > 24);
    assert(result%5 ==0);

    //interactive-based Testing
    result = printColorMap(&fakeManualPrinterMock);
        // Initialize the expectedManualList
    
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int index = i * 5 + j;
            assert(colorCodeManualItem[index].capturedColorCode == index);
            assert(strcmp(colorCodeManualItem[index].capturedMajorColor, majorColors[i]) == 0);
            assert(strcmp(colorCodeManualItem[index].capturedMinorColor, minorColors[j]) == 0);
        }
    }

int main() {
    test_cases();
    printColorMap(&printColorCodeManualOnConsole); //print color map to console
    printf("All is well (maybe!)\n");
    return 0;
}
