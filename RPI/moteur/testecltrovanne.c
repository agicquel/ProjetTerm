
#include <stdio.h>
#include <wiringPi.h>

#define A 15
#define B 16
int main (void)
{
  wiringPiSetup () ;
//  pinMode (A, OUTPUT) ;
  pinMode (B, OUTPUT) ;

//  digitalWrite (A, HIGH);
while(1) 
{
  digitalWrite (B, LOW);
//  digitalWrite (A, HIGH); delay (5000);

 // digitalWrite (B, HIGH);
 // digitalWrite (A, LOW); delay (5000);

}


/*
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
*/

  return 0 ;
}

