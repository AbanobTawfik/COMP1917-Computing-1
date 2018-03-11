#include <stdio.h>
#include <string.h>
void readfile(void);
int main(void){
    readfile();
    return 0;
}
void readfile(void){
	FILE* input;
	char truffle[]="truffle";
	char trufflecompare[10];
	char inputfile[16];
	int i;
	for(i=0;i<100;i++){
	   sprintf(inputfile,"area%d",i);	
	   input = fopen(inputfile,"r");
	   if(input==NULL){
	   	printf("Error opening the file\n");
	   }else{
	   	while(fscanf(input,"%s",trufflecompare)!=EOF){
		   	if(strcmp(truffle,trufflecompare)==0){
		   		printf("%s\n",inputfile);
		   		break;
		   	}
		   }
		}
	   fclose(input);
	}
}