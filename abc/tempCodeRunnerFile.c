#include <stdio.h>

#define SIZE 10 + 10

int main(void)
{
   int total = 0;
   
   printf("10 + 10 = %d\n", SIZE);
   
   printf("(10 + 10) * (10 + 10) = %d\n", SIZE * SIZE);
   
   // NOTE: how 'define' replace the content with string (uncalculated) 
   
   return 0;
}