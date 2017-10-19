#!/usr/bin/env python
# Author: Ian Kirkpatrick
# CPS 340
# Random number generator for quicksort algorithm
import random
import sys

def generate_random_numbers(n=100):
	"""
	Returns a list of randomly generated numbers that is
	`n` elements long. Uses random.random().
	"""
	return [int(random.random() * 100) for x in xrange(n)]

def __main__():
	if len(sys.argv) == 2 and sys.argv[1].isdigit():
		numbers = generate_random_numbers(int(sys.argv[1]))
		sys.stdout.write(", ".join([str(x) for x in numbers]))
		sys.stdout.write("\n")

if __name__ == "__main__": __main__()

