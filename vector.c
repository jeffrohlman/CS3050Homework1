/*
 * Vector component Homework 1 for CS3050 at University of Columbia
 * Contains all vector functions specified in vector.h
 */

#include "vector.h"

void init_vector(struct vector* v)
{
	v->data = malloc(sizeof(int) * INIT_VECTOR_SIZE);
        v->frequency = malloc(sizeof(int) * INIT_VECTOR_SIZE);
	v->size = 0;
	v->capacity = INIT_VECTOR_SIZE;
}

int access_element_vector(struct vector* v, size_t index)
{
	if(index >= v->size)
		exit(OUT_OF_BOUNDS);
	return v->data[index];
}

int access_frequency_vector(struct vector * v, size_t index)
{
    if(index >= v-> size)
        exit(OUT_OF_BOUNDS);
    return v->frequency[index];
}

int get_vector_size(struct vector * v){
    return v -> size;
}

void insert_element_vector(struct vector* v, int element_to_insert)
{
	if(v->capacity == v->size)
	{
		v->data = realloc(v->data, sizeof(int) * v->capacity * 2);
                v->frequency = realloc(v->frequency, sizeof(int) * v->capacity * 2);
		v->capacity *= 2;
	}
	v->data[v->size] = element_to_insert;
        v->frequency[v->size] = 1;
	v->size += 1;
}

void increase_frequency_vector(struct vector* v, size_t index)
{
        if(index >= v-> size)
            exit(OUT_OF_BOUNDS);
        
        v->frequency[index] += 1;
}

int* vector_get_ptr(struct vector* v)
{
	return v->data;
}

int* vector_get_ptr_freq(struct vector * v){
    return v->frequency;
}

void free_vector(struct vector* v)
{
	free(v->data);
        free(v->frequency);
	v->size = 0;
}

void merge(int * arr, int leftIndex, int middle, int rightIndex)
{  
    int i, j, k;
    int L1 = middle - leftIndex + 1;
    int L2 =  rightIndex - middle;
 
    //int L[L1], R[L2];
    int* L = malloc(sizeof(int) * L1);
    int* R = malloc(sizeof(int) * L2);
 
    for (i = 0; i < L1; i++)
        L[i] = arr[leftIndex + i];
    for (j = 0; j < L2; j++)
        R[j] = arr[middle + 1+ j];
 
    i = 0; 
    j = 0; 
    k = leftIndex; 
    while (i < L1 && j < L2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
           arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < L1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < L2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}
 

void vectorMergeSort(int * arr, int leftIndex, int rightIndex)
{
    
    if (leftIndex < rightIndex)
    {
        int middle = (leftIndex+rightIndex)/2;
 
        vectorMergeSort(arr, leftIndex, middle);
        vectorMergeSort(arr, middle+1, rightIndex);
 
        merge(arr, leftIndex, middle, rightIndex);
    }
}

void frequencyMerge(int * arr, int * arr2, int leftIndex, int middle, int rightIndex)
{
    int i, j, k;
    int L1 = middle - leftIndex + 1;
    int L2 =  rightIndex - middle;
 
    int L[L1], R[L2], FL[L1], FR[L2];
 
    for (i = 0; i < L1; i++){
        L[i] = *(arr + (leftIndex + i));
        FL[i] = *(arr2 + (leftIndex + i));
    }
    for (j = 0; j < L2; j++){
        R[j] = *(arr + (middle + 1 + j));
        FR[j] = *(arr2 + (middle + 1 + j));
    }
 
    i = 0; 
    j = 0; 
    k = leftIndex; 
    while (i < L1 && j < L2)
    {
        if (L[i] <= R[j])
        {
            *(arr + k) = L[i];
            *(arr2 + k) = FL[i];
            i++;
        }
        else
        {
           *(arr + k) = R[j];
           *(arr2 + k) = FR[j];
            j++;
        }
        k++;
    }
 
    while (i < L1)
    {
        *(arr + k) = L[i];
        *(arr2 + k) = FL[i];
        i++;
        k++;
    }
 
    while (j < L2)
    {
        *(arr + k) = R[j];
        *(arr2 + k) = FR[j];
        j++;
        k++;
    }
}

void vectorFrequencyMergeSort(int * arr, int * arr2, int leftIndex, int rightIndex)
{
    
    if (leftIndex < rightIndex)
    {
        int middle = leftIndex+(rightIndex-leftIndex)/2;
 
        vectorFrequencyMergeSort(arr, arr2, leftIndex, middle);
        vectorFrequencyMergeSort(arr, arr2, middle+1, rightIndex);
 
        frequencyMerge(arr, arr2, leftIndex, middle, rightIndex);
    }
}