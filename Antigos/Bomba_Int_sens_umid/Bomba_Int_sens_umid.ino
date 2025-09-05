// C++ code
//
#include <Servo.h>

Servo servo_11;

void setup()
{
  servo_11.attach(11, 500, 2500);
}

void loop()
{
  servo_11.write(180);
  delay(1000); // Wait for 1000 millisecond(s)
  servo_11.write(0);
  delay(1000); // Wait for 1000 millisecond(s)
}
