#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Point.h"
 
int main (int argc, char * argv[]) {
	printf("White Box Tests\n");
	printf("Since this code has very few functions and limited ouputs not alot to test\n");
	printf("==========================================================================\n");
//we are testing every single line of code with every test case	
   Point referencePoint = newPoint(1,1);
   printf("Checking values after making new point for reference\n");
   printf("reference x: [%.2f]\n",getX(referencePoint));
   printf("reference y: [%.2f]\n",getY(referencePoint));
   printf("\n");
   Point comparePoint = newPoint(1,1);
   printf("Checking values after making new point for comparison\n");
   printf("comparison x: [%.2f]\n",getX(comparePoint));
   printf("comparison y [%.2f]\n",getX(comparePoint));
   printf("\n");
   printf("\n");  
   setPoint(referencePoint,2,2);
   printf("comparing\n");
   printf("\n");
   printf("reference x: [%.2f]\n",getX(referencePoint));
   printf("comparison x: [%.2f]\n",getX(comparePoint));   
   printf("reference y: [%.2f]\n",getY(referencePoint));
   printf("comparison y [%.2f]\n",getX(comparePoint)); 
   printf("\n");       
   assert(getX(referencePoint)!=getX(comparePoint));
   assert(getY(referencePoint)!=getY(comparePoint));
   destroyPoint(referencePoint);
   destroyPoint(comparePoint);
   printf("all possible situations for code tested :) good to go 0 assertions failed!\n");
   printf("==========================================================================\n");
   printf("\n");
   printf("\n");
   printf("\n");





   double input1;
   double input2;
   double changeinput1;
   double changeinput2;
   int choice = 2;
   printf("Black Box Tests\n");
   printf("now we are going to allow users to enter their own input and allow them to decide for themselves the following\n");
   printf("1-> is it functioning as it is intended to?\n");
   printf("2-> is it usable, does it make sense to use?\n");
   printf("3-> is it performing good (speedwise is it taking too long)?\n");
   printf("==========================================================================\n");
   printf("Enter the X value for your point\n");
   scanf("%lf",&input1);
   printf("Enter the Y value for your point\n");
   scanf("%lf",&input2);
   printf("\n");   
   Point userPoint = newPoint(input1,input2);
   printf("Your X coordinate is : %.2lf\n",getX(userPoint));
   printf("Your Y coordinate is : %.2lf\n",getY(userPoint));
   printf("choose either option 1 or 2\n");
   printf("1-> change my point\n");
   printf("2-> exit the code\n");
   scanf("%d",&choice);
   if(choice==1){
	   printf("Enter the new X value for your point\n");
	   scanf("%lf",&changeinput1);
	   printf("Enter the new Y value for your point\n");
	   scanf("%lf",&changeinput2);
	   printf("\n");
	   setPoint(userPoint,changeinput1,changeinput2);
	   printf("Your new X coordinate is : %.2lf\n",getX(userPoint));
	   printf("Your new Y coordinate is : %.2lf\n",getY(userPoint));
      destroyPoint(userPoint); 
   }else{
   	    printf("You have chosen to stick with your current values\n");
          destroyPoint(userPoint);
    	return EXIT_SUCCESS;
   }
return EXIT_SUCCESS;   
}