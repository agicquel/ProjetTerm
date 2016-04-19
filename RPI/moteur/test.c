 #include <wiringPi.h>

#define A 0
#define B 1
#define D 2
#define C 3

#define speed 4

int main (void)
{
  wiringPiSetup () ;
  pinMode (A, OUTPUT) ;
  pinMode (B, OUTPUT) ;
  pinMode (C, OUTPUT) ;
  pinMode (D, OUTPUT) ;

  for (;;)
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

//    digitalWrite (8, LOW) ; delay (500) ;
//    digitalWrite (10, LOW) ; delay (500) ;
//    digitalWrite (12, LOW) ; delay (500) ;
//    digitalWrite (16, LOW) ; delay (500) ;

//    digitalWrite (0,  LOW) ; delay (500) ;
  }
  return 0 ;
}
