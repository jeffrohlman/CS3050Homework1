/*
 * Seeder project for Homework 1 of CS3050 at University of Missouri - Columbia
 * Automatically writes to Homework 1 input file
 * Numbers can be changed to try different inputs
 */

/* 
 * File:   main.c
 * Author: Jeff Rohlman
 *
 * Created on September 4, 2017, 12:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
/*
 * 
 */
int main(int argc, char** argv) {

    FILE * fptr = fopen("../input.txt", "w");
    int i = 0;
    srand(time(NULL));
    //INT_MAX
    for(; i < 1000000; i++){
        fprintf(fptr, "%d\n", rand() % 10 + 1);
    }
    
    fclose(fptr);
    return (EXIT_SUCCESS);
}

