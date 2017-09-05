/*
 * Homework1 for CS3050 at the University of Columbia
 * Reads from input file integers line by line
 * Sorts by frequency of same number in ascending order
 * In the case of same frequency it sorts in ascending numerical order
 */

/* 
 * File:   main.c
 * Author: Jeff Rohlman
 *
 * Created on August 29, 2017, 6:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "input_error.h"
#include "vector.h"
#include <ctype.h>

void parse_getline(FILE*, struct vector*);
void parseline(char *);
void countFreq(struct vector *, struct vector *);

int main(int argc, char** argv) {
    if(argc != 3)
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    
    FILE* fptr = fopen(*(argv + 1), "r");
    if(!fptr)
        exit(INPUT_FILE_FAILED_TO_OPEN);
    
    struct vector inputs;
    init_vector(&inputs);
    
    parse_getline(fptr, &inputs);
    if(get_vector_size(&inputs) == 0)
        exit(PARSING_ERROR_EMPTY_FILE);
    
    int i = 0; 
    
    vectorMergeSort(vector_get_ptr(&inputs), 0, get_vector_size(&inputs) - 1);
    
    struct vector freq;
    init_vector(&freq);
    
    countFreq(&freq, &inputs);
     
    vectorFrequencyMergeSort(vector_get_ptr_freq(&freq) , vector_get_ptr(&freq), 0, get_vector_size(&freq) - 1);
    
    FILE* ofptr = fopen(*(argv + 2), "w");
    if(!ofptr)
        exit(OUTPUT_FILE_FAILED_TO_OPEN);
    
    for(i = 0; i < get_vector_size(&freq); i++)
        fprintf(ofptr,"%d\n", access_element_vector(&freq, i));
    
    if((fclose(ofptr)) != 0)
        exit(OUTPUT_FILE_FAILED_TO_CLOSE);
    
    if((fclose(fptr)) != 0)
        exit(INPUT_FILE_FAILED_TO_CLOSE);
    
    free_vector(&inputs);
    free_vector(&freq);
    
    return (EXIT_SUCCESS);
}

//Function that scans file and pulls each line one at a time
//Send individual lines to parseline to check for non digit characters
//Adds to vector once determined to be an integer
void parse_getline(FILE* fp, struct vector* v) {
	char* line = NULL;
	size_t nbytes = 0;
        int linelen=0;
	while ((linelen=getline(&line, &nbytes, fp)) != -1) {
		line[linelen-1] = '\0'; 
		parseline(line);
                insert_element_vector(v, atoi(line));
                
	}

	free(line);
}

//Function to take in single line and parse for non digit characters
//If the function encounters a non digit character the program is exited
void parseline(char *line) {
	char c;
        int i=0;
        

	while ((c = *(line + i++)) != '\0') {
		if (!isdigit(c))
                    exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
	}
}

//Goes through sorted vector and counts frequencies
//Takes frequency vector and initial input vector
void countFreq(struct vector *freq, struct vector *inputs){
    int i = 0, temp = -1, j = -1;
    for(; i < get_vector_size(inputs); i++){
        if(temp == access_element_vector(inputs, i))
            increase_frequency_vector(freq, j);
        else{
            temp = access_element_vector(inputs, i);
            insert_element_vector(freq, temp);
            j++;  
        }
    }
}