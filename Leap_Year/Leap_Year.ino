//Toast_Leap_Year

#include <ArduinoUnit.h>

bool toast_is_a_leap_year(int toast_year)
{
  return (((toast_year % 4 == 0) and ((toast_year % 100) != 0)) or ((toast_year % 400) == 0));
}

test(toast_a_typical_common_year_return_false)
{
  assertFalse(toast_is_a_leap_year(2001));
}

test(toast_a_leap_year_returns_true)
{
  assertTrue(toast_is_a_leap_year(1996));
}

test(toast_an_atypical_common_year_return_false)
{
  assertFalse(toast_is_a_leap_year(1900));
}

test(toast_an_atypical_leap_year_returns_true)
{
  assertTrue(toast_is_a_leap_year(2000));
}

void setup() {
  Serial.begin(115200);
  //year = Serial.read();
  
}

void loop() {
  Test::run();  
}
