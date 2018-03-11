#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_COURSES 4
#define PS 50
#define CR 65
#define DN 75
#define HD 85
typedef struct _student {
	int zid;
	double wam;
}
student;
double calcAvg(double marks[], int size);
student * getData(int numStudents);
int getNumFails(student * students, int numStudents);
int getPrize(student * students, int numStudents);
int main (int argc, char * argv[]) {
	//get number of students
	int numStudents;
	int winner;
	printf("How many students do you want to calculate marks for? ");
	scanf("%d", &numStudents);
	//get students
	student * students = getData(numStudents);
	//find out how many failed
	int numFailes = getNumFails(students, numStudents);
	if (numFailes == 0) {
		printf("Yay everyone passed!\n");
	} else {
		printf("%d students failed :(\n", numFailes);
	}
	//get university prize winner
	winner = getPrize(students, numStudents);
	printf("The winner is z%d\n", winner);
	free(students);
	return EXIT_SUCCESS;
}
student * getData(int numStudents) {
	//this function returns an array of students
	//with information entered by a user
	//malloc array
	student * students = malloc(sizeof(student)*numStudents);
	assert(students != NULL);
	//enter each student's info
	int numCourses;
	int i = 0;
	int size = numStudents;
	while (i < size) {
		//get zid
		printf("zID of student %d: ", (i+1));
		scanf("%d", &students[i].zid);
		//get num courses
		printf("How many courses is student z%d taking? ", students[i].zid);
		scanf("%d", &numCourses);
		assert(numCourses <=MAX_COURSES);
		double * marks = malloc(sizeof(double) * numCourses);
		//get course marks
		printf("Please enter the marks for each course on a new line:\n");
		int j = 0;
		while (j <numCourses) {
			scanf("%lf", &marks[j]);
			assert((marks[j]) <= 100);
			assert(marks != NULL);
			j++;
		}
		//calculate wam
		students[i].wam = calcAvg(marks,numCourses);
		i++;
		free(marks);
	}
	return students;
}
double calcAvg(double marks[], int size) {
	//calculate the average of an array of doubles
	int i = 0;
	double total = 0;
	//get sum of all marks
	while (i < MAX_COURSES) {
		total += marks[i];
		i++;
           if(marks[i+1]=='\0'){
              break;
           }
	}
	//get average
	double avg = total / i;
	return avg;
}
int getNumFails(student * students, int numStudents) {
	//calculate how many students failed
	int i = 0;
	int failures = 0;
	while (i < numStudents) {
		//if they haven't passed, increment counter
		if (students[i].wam < PS) {
			failures++;
		}
		i++;
	}
	return failures;
}
int getPrize(student * students, int numStudents) {
	int i = 0;
	int max = 0;
	int winner;
	//find student with highest wam
	while (i < numStudents) {
		//if current student wam greater than max wam
		//current student is now highest wam
		
                if (students[i].wam >= max) {
			max = students[i].wam;
			winner = students[i].zid;
		}
		i++;
	}
        int j = 0;
        for(i=0;i<=numStudents;i++){
		if(students[i].wam==students[i+1].wam){
			j++;		
		}        
	}
        if(j>0){
		srandom(420);
      	        i = rand()%j;
      	        winner = students[j].zid;
	}
	return winner;
}
