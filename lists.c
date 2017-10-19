#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lists.h"

/**
 * Author: Ian Kirkpatrick
 * CPS 340
 * Code for doing things with lists. This is a util file.
 * This file contains the logic for quicksort 
 */

void print_list(int count, int list[]) {
	int i = 0;

	printf("[");
	for (; i < count-1; i ++) {
		printf("%d, ", list[i]);
	}
	if (count > 0) printf("%d", list[count-1]);
	printf("]\n");
}

/*
partition_code's:
	
	1: Use Lomuto's Partition
	2: Use Hoare's Partition

Returns the number of seconds it takes for this algorithm to run.
To get the number of seconds:
	
	#include <time.h>
	int elapsed = quicksort(...);
	int msec = elapsed * 1000/CLOCKS_PER_SEC;
	int seconds = msec/1000;
	int milliseconds_remaining_after_seconds = msec%1000;
*/
int quicksort(int list[], int low, int high, int partition_code){
	void print_list(int, int[]);
	int lomuto_partition(int[], int, int);	
	int hoare_partition(int[], int, int);	

	int part_index;
	
	clock_t start = clock(), diff;
	if (low < high) {
		
		if (partition_code == 1) {
			part_index = lomuto_partition(list, low, high);
		} else if (partition_code == 2) {
			part_index = hoare_partition(list, low, high);
		} else {
			fprintf(stderr, "%d is not a supported partition code.", partition_code);
			return 0;
		}
		quicksort(list, low, part_index - 1, partition_code);
        quicksort(list, part_index + 1, high, partition_code);
	}
	diff = clock() - start;
	
	return diff;
}

int lomuto_partition (int list[], int low, int high) {
	void arrswap(int[], int, int);	

	int pivot = list[high];
 
	int i = (low - 1);
	int j = low;

	for (; j < high; j++)
	{
		if (list[j] <= pivot)
		{
			i++;
			arrswap(list, i, j);
		}
	}
	arrswap(list, i + 1, high);
	return (i + 1);
}

int hoare_partition(int list[], int low, int high) {
	void arrswap(int[], int, int);

	int pivot = list[low];
    int i = low - 1, j = high + 1;
  
    while (1)
    {
        do
        {
            i++;
        } while (list[i] < pivot);
  
        do
        {
            j--;
        } while (list[j] > pivot);
  
        if (i >= j)
            return j;
  
        arrswap(list, i, j);
    }
	
	fprintf(stderr, "Hoare's partition broke :(.");
	return 0;
}

void arrswap(int list[], int a, int b) {
	int temp = list[b];
	list[b] = list[a];
	list[a] = temp;
}
