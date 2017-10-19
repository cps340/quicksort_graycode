#!/usr/bin/env python
# Author: Ian Kirkpatrick
# CPS 340
# Graycode algorithm
import sys

def graycode(n=1):

	if n == 1: gc = [[False],[True]]
	else:
		l1 = graycode(n-1)
		l2 = cpymtrx(l1, True)
		append_val_to_matrix(l1, False)
		append_val_to_matrix(l2, True)
		gc = l1 + l2
	return gc

def append_val_to_matrix(matrix, val):
	for x in xrange(len(matrix)):
		matrix[x] = [val] + matrix[x]

def cpymtrx(matrix, reverse=False):
	cpy = [x[:] for x in matrix]
	if reverse: cpy.reverse()
	return cpy

def test_graycode():
	tested = graycode(3)
	expected = [
		[0,0,0],
		[0,0,1],
		[0,1,1],
		[0,1,0],
		[1,1,0],
		[1,1,1],
		[1,0,1],
		[1,0,0],
	]
	if tested == expected: print("Graycode method works!")
	else: print("Graycode method failed. output: {}".format(str(tested)))

def print_matrix_as_binary_list(matrix):
	new_matrix = ["".join([str(int(bit)) for bit in code]) for code in matrix]
	print(str(new_matrix))

def __main__():
	if len(sys.argv) == 2 and sys.argv[1] == "test":
		test_graycode()
	elif len(sys.argv) == 2 and sys.argv[1].isdigit():
		validate_input_n()
		n = int(sys.argv[1])
		gc = graycode(n)
		print_matrix_as_binary_list(gc)

def validate_input_n():
	n = int(sys.argv[1])
	if n > 20:
		sys.stderr.write("You are going to kill me!\n")
		exit(1)

if __name__ == "__main__":
	__main__()

