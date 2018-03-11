#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
   double area = 0;
   double a = 0;
   double b = 0;
   double c = 0;
   double s = 0;
   printf("Enter sidelengths of a triangle:\n");
   scanf("%lf %lf %lf",&a,&b,&c);
   s=(a+b+c)/2;
   area=sqrt(s*(s-a)*(s-b)*(s-c));
   if(a+b<c || area<0)
   {
      printf("error"); 
   }
   else
   {
      printf("Area = %.2lf\n", area);
   }
   return EXIT_SUCCESS;
}
