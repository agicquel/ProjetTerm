#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define A 15
#define speed 4000

int main (void)
{
  wiringPiSetup () ;
  wiringPiI2CSetup();
  int read;
  pinMode (A, OUTPUT) ;

  for (;;)
  {
    digitalWrite (A, HIGH) ;
    read = wiringPiI2CRead();
    printf("read = %d", read);
    delay (speed) ;
    digitalWrite (A, LOW) ;
    delay (speed) ;
  }
  return 0 ;
}
