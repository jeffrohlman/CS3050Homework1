#ifndef H_VECTOR_H
#define H_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_VECTOR_SIZE 512

enum vector_errors
{
	OUT_OF_BOUNDS = 0,
};

struct vector
{
	int* data;
        int* frequency;
	int size;
	int capacity;
};

void init_vector(struct vector* v);
int access_element_vector(struct vector* v, size_t index);
void insert_element_vector(struct vector* v, int element_to_insert);
void free_vector(struct vector* v);
int get_vector_size(struct vector * v);
int* vector_get_ptr(struct vector* v);
void merge(int * arr, int leftIndex, int middle, int rightIndex);
void vectorMergeSort(int * arr, int leftIndex, int rightIndex);
void increase_frequency_vector(struct vector* v, size_t index);
int access_frequency_vector(struct vector * v, size_t index);
void frequencyMerge(int * arr, int * arr2, int leftIndex, int middle, int rightIndex);
void vectorFrequencyMergeSort(int * arr, int * arr2, int leftIndex, int rightIndex);
int* vector_get_ptr_freq(struct vector * v);

#endif
