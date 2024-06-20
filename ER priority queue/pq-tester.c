#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "emalloc.h"

#define MAX_LINE_LEN 5000

void inccounter(Patient *p, void *arg) {
    /* DO NOT CHANGE THIS FUNCTION. */
    int *ip = (int *)arg;
    (*ip)++;
}


void print_word(Patient *p, void *arg) {
    /* DO NOT CHANGE THIS FUNCTION. */
    char *fmt = (char *)arg;
    printf(fmt, p->name, p->birth_year, p->priority);
}


void dump(Patient *list) {
    /* DO NOT CHANGE THIS FUNCTION. */
    int len = 0;

    apply(list, inccounter, &len);    
    printf("Number of patients: %d\n", len);

    apply(list, print_word, "%s,%d,%d\n");
}

Patient *tokenize_line(char *line) {
    /* TODO: You have to implement this function to tokenize a line
        and either:
        1) return a valid Patient pointer if the line command is enqueue
        2) return NULL if the line command is dequeue
    */
	
	char separator[]=",\n";

	char* portion=strtok(line,separator);

	//will hold the values/info of the line
	char arr[4][MAX_LINE_LEN];

	char string[]="enqueue";
	
	//compares the string to the first command/text
	int result=strcmp(portion,string);
	
	int counter=0;

	
	while(portion!=NULL){

		//initializing the values from the current line into arr
		strcpy(arr[counter],portion);
		counter++;
		portion=strtok(NULL,separator);


	}

	
	//if result is 0 then it means that the line is asking to be enqueued
	if(result==0){
	
		

	//creating the pointer/node

	Patient *newpatient;
	newpatient=(Patient *) emalloc(sizeof(Patient));
	newpatient->name= strdup(arr[1]);
	newpatient->birth_year=atoi(arr[2]);
	newpatient->priority=atoi(arr[3]);
	
	return newpatient;

	}
	
	//otherwise if the above if statement was not satisfied then we return NULL to indicate the dequeued command
	return NULL;

	

	



}

Patient *read_lines(Patient *list) {
    /* TODO: You have to implement this function to tokenize all lines
        from the stdin. You HAVE TO use the tokenize_line function
        as an auxiliary function to parse each line.
        If tokenize_line returns a valid Patient pointer, add the
        patient to the list with the correct priority.
        Otherwise, dequeue the first patient from the list.
        At the end of the function, return the list to the caller.       
    */
	//set the line string length
 	char string[MAX_LINE_LEN];
	

	
	//loop through the stdin
	while(fgets(string,MAX_LINE_LEN,stdin)!=NULL){
		
		//creates a pointer and initialize it with the pointer/node returned by "tokenize_line"
		Patient *newpatient;
		newpatient=tokenize_line(string);
	
		
		//if the pointer has a value of NULL this means that it is asking to be dequeued
		if(newpatient==NULL){

			//updates the list
			list=remove_front(list);
			

		}
		
		else{
			//updates the list with the newly modified list 
			list=add_with_priority(list,newpatient);
			
			
		}

		
		
	}
	
		
	//returns the list
	return list;
	
}

void deallocate_memory(Patient *list) {
    /* TODO: You have to implement this function to deallocate (free) 
        memory from the list before the program ends
    */

	//checks to see if the list is already empty, and if it is then it won't be necessary to free an already empty pointer
	if(list==NULL){
	return;
	}
	
	//Otherwise we create a new pointer and loop through the list
	Patient *next=list->next;
	Patient *curr;

	for(curr=list;curr!=NULL;curr=next){
		//moving forward while deleting the node behind it!
		next=curr->next;
		free(curr);


	}

    
}


int main(int argc, char *argv[]) {
    /* DO NOT CHANGE THE MAIN FUNCTION. YOU HAVE TO IMPLEMENT YOUR
        CODE TO FOLLOW THE SEQUENCE OF INSTRUCTIONS BELOW. */
    Patient *list = NULL;

    if (argc != 1) {
            printf("Usage: %s\n", argv[0]);
            printf("Should receive no parameters\n");
            printf("Read from the stdin instead\n");
            exit(1);
    }

    list = read_lines(list);
 
    dump(list);
    
    deallocate_memory(list);

    exit(0); 
}
