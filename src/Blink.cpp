#include <Arduino.h>

extern "C" void initialise_monitor_handles(void);

void setup();
void loop();

#define LED PC13

void setup()
{
    initialise_monitor_handles();
    pinMode(LED, OUTPUT);
}

int cnt = 0;

void loop()
{ 
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    printf("Count value: %d\n", cnt++);
}


// This function prevents that the compilation ends with next error message
// "undefined reference to `std::__throw_bad_function_call()'"
// TODO: find out how to do this better
//
namespace std {
    void __throw_bad_function_call() {
        Serial.println(F("STL ERROR - __throw_bad_function_call"));
        __builtin_unreachable();
    }
}
