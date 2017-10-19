##Requirements:
* Linux/Unix environment
* Gnu Compiler
* Makefile compatibility for building C source code.
* python (preferably 2.7.?)

##How to Run:

**To run the quicksort algorithm:**

1. cd into the projects root folder.
2. Build the C code for the quiksort alrgorithms.
	* Run *make clean a3*
3. Run *python main.py*

**To run the graycode algorithm:**

1. cd into the projects root folder.
2. Run *python graycode.py #*.
	* # is the value for n. The graycode will build elements of this length.
	* Example, *python graycode.py 3* will output 000, 001, 011, ... while *python graycode.py 2* will output 00, 01, 11, 10.
