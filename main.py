#!/usr/bin/env python
# Author: Ian Kirkpatrick
# CPS 340
# main for running quicksort algorithms
import os

import random_generator.random_numbers as random_numbers

sort_program = "./a3"

def run_sort(n=100):
	numbers = random_numbers.generate_random_numbers(n)
	arguments_str = " ".join([str(x) for x in numbers])
	os.system("{} {}".format(sort_program, arguments_str))

def __main__():
	runs = [5000, 10000, 15000, 20000, 25000, 30000, 35000,
			40000, 45000, 50000, 55000, 60000, 65000, 70000,
			75000, 80000, 85000, 90000, 95000, 100000]
	for x in runs:
		run_sort(x)

if __name__ == "__main__": __main__()
