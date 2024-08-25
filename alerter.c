
#include <math.h>
#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
float capturedCelcius;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 
    if(isnan(celcius) || isinf(celcius))
    {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int networkAlertMock(float celcius) {
      capturedCelcius=celcius;
   return 500;
}

//TestCases
void test_cases(){
        alertInCelcius(NAN);
        alertInCelcius(INFINITY);
        alertInCelcius(400.5);
        alertInCelcius(303.6);
        alertInCelcius(500);
        alertInCelcius(-5);
        printf("%d alerts failed.\n", alertFailureCount);
        assert(alertFailureCount == 3);

      assert(alertFailureCount == 1); //State Based Testing
      alertFailureCount=0;
      float expectedCelcius=200;
      alertInCelcius(400.5,&networkAlertMock);
      assert(expectedCelcius == capturedCelcius);
}

int main() {
    test_cases();
    printf("All is well (maybe!)\n");
    return 0;
}
