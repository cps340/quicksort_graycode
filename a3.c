#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lists.h"

/**
 * Author: Ian Kirkpatrick
 * CPS 340
 * main for running quicksort algorithms
 */

int *argvtois(int argc, char *argv[]) {
	int *argi;
	int next_val;
	int i = 1;	
	
	argi = malloc((argc-1)*sizeof(int));

	for (; i < argc; i ++) {
		next_val = atoi(argv[i]);
		argi[i-1] = next_val;
	}

	return argi;
}

void print_time_elapsed(int time_elapsed, char *message) {
	int msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
	/*int seconds = msec/1000;
	int milliseconds = msec % 1000;*/
	printf("%s ran in %d nanoseconds\n", message, msec);
}

int main(int argc, char *argv[]) {
	int *argvtois(int, char*[]);
	void print_list(int, int[]);
	int quicksort(int[], int, int, int);

	int *input_nums;
	int *input_nums2;
	int argcount;

	argcount = argc - 1;

	input_nums = argvtois(argc, argv);
	input_nums2 = argvtois(argc, argv);
	
	int time_elapsed = quicksort(input_nums, 0, argcount-1, 1);
	print_time_elapsed(time_elapsed, "Lomuto's Quicksort");

	time_elapsed = quicksort(input_nums2, 0, argcount-1, 2);
	print_time_elapsed(time_elapsed, "Hoare's Quicksort");

	printf("===============================================\n");
	/*print_list(argcount, input_nums);*/
	
	exit(0);
}

