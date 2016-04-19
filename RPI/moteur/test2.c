#include <stdio.h>
#include <wiringPi.h>

#define D 5
#define A 6
#define B 10
#define C 11

#define speed 3

int main (void)
{
  wiringPiSetup () ;
  pinMode (A, OUTPUT) ;
  pinMode (B, OUTPUT) ;
  pinMode (C, OUTPUT) ;
  pinMode (D, OUTPUT) ;

  int i;

while(1)
{

  for (i = 0; i < 512; i++)
  {
    digitalWrite (A, HIGH) ;
    digitalWrite (B, HIGH) ; delay (speed) ;
    digitalWrite (A, LOW) ;
    digitalWrite (C, HIGH); delay (speed) ;
    digitalWrite (B, LOW);
    digitalWrite (D, HIGH); delay (speed) ;
    digitalWrite (C, LOW) ;
    digitalWrite (A, HIGH) ; delay (speed) ;
    digitalWrite (D, LOW) ;
  }
}

  return 0 ;
}
