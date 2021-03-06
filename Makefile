#################################################################
# Read the handout makeandmakefile.pdf for details.
# variables, flags for CFLAGS
# -Wall flags all errors
# -Werror treats warning as an error
# -g  includes symbol table to help gdb
#
#################################################################
A = a3

CFLAGS  = -g -Wall -Werror -ansi
LDFLAGS =
CC	= gcc
LD	= gcc

PROG	= $(A)
CEESRCS = $(A).c

OBJS    = lists.o $(A).o

#################################################################
# rules:
# indented lines have a tab (^I) at the start of line!!
#################################################################

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ $(PROG)

#################################################################
# dependencies -- none in this program
#################################################################
