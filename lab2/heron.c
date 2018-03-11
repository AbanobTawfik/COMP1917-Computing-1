#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
   int area = 0;
   int a = 0;
   int b = 0;
   int c = 0;
   printf("Enter sidelengths of triangle:\n");
   scanf("%d %d %d",&a,&b,&c);
   s=(a+b+c)/2;
   area=sqrt(s*(s-a)*(s-b)*(s-c);
   if(a+b<c || area<0)
   {
      printf("error"); 
   }
   else
   {
      printf("your area is %d\n", area);
   }
   return EXIT_SUCCESS;
}
