#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

void binary_search(int *array, int size, int find_num);
void print_array(int *array, int size);
void selectionSort(int *array, int size);
void bubble_sort(int *array, int size);
void improved_bubble_sort(int *array, int size);
void mergeSort(int *A, int lb, int ub);
void merge(int *A, int lb, int mid, int ub);
#endif