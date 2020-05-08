# CISC-361 Operating Systems homework assignment #3
# By: William Cantera
# Email: wcantera@udel.edu
# Student ID: 702464888
#
# NOTE: I worked alone

CC = gcc

all: fork-join rendezvous order

fork-join.o: fork-join.c Makefile
		${CC} -c fork-join.c

fork-join: fork-join.o Makefile
		${CC} fork-join.o -o fork-join -lpthread

rendezvous.o: rendezvous.c Makefile
		${CC} -c rendezvous.c

rendezvous: rendezvous.o Makefile
		${CC} rendezvous.o -o rendezvous -lpthread

order.o: order.c Makefile
		${CC} -c order.c

order: order.o Makefile
		${CC} order.o -o order -lpthread

clean:
		rm -rf *.o fork-join rendezvous