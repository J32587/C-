#include <iostream>
#include <stdio.h>
#include <math.h>

bool testFloat(long double);

int main(void)
{
 int a,b,c;

 long double outputOne;
 long double outputTwo;
 long double sqrtCalc;
 int sqrtPrev;

 printf("a = ");
 std::cin >> std::dec >> a;

 if(std::ios::failbit == std::cin.rdstate())
 {
  printf("Invalid input for \"a\"\n");
  return std::ios::failbit;
 }

 printf("b = ");
 std::cin >> std::dec >> b;

 if(std::ios::failbit == std::cin.rdstate())
 {
  printf("Invalid input for \"b\"\n");
  return std::ios::failbit;
 }

 printf("c = ");
 std::cin >> std::dec >> c;

 if(std::ios::failbit == std::cin.rdstate())
 {
  printf("Invalid input for \"c\"\n");
  return std::ios::failbit;
 }

 const int negB = (b * -1);

 if(a == 0)
 {
  printf("\n\"a\" cannot be zero\n");
  return -1;
 }

 sqrtPrev = ( (b * b) - (4 * a * c) );

 sqrtCalc = sqrt(sqrtPrev);

 if(errno == EDOM)
 {
  sqrtCalc = sqrt(sqrtPrev * -1);

  printf(" \n\n\n X = ( %d + \u221A%di ) / %d\n", negB, (sqrtPrev * -1),(2 * a) );
  printf(" X = ( %d - \u221A%di ) / %d\n", negB, (sqrtPrev * -1),(2 * a) );

  outputOne = (negB + sqrtCalc) / (2 * a);

  outputTwo = (negB - sqrtCalc) / (2 * a);

  printf(" \n\n\n X = %Lfi\n", outputOne);
  printf(" X = %Lfi\n", outputTwo);

  return EDOM;
 }

 else if(testFloat(sqrtCalc))
 {
  printf("\n\n\n X = ( %d + \u221A%d ) / %d\n",negB, (sqrtPrev),(2 * a) );
  printf(" X = (%d - \u221A%d ) / %d\n",negB, (sqrtPrev),(2 * a) );
 }

 outputOne = ( negB + sqrtCalc ) / (2 * a);

 outputTwo = ( negB - sqrtCalc ) / (2 * a);

 printf("\n\n\n X = %Lf\n", outputOne);
 printf(" X = %Lf\n", outputTwo);

return 0;
}

bool testFloat(long double input)
{
 int x = input * 10;

 if( (x % 10) == 0) return false;
 else return true;
}
