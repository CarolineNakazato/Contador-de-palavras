###      MAKEFILE      ###
# Caroline  RA: 17164260 #
# Stephanie RA: 15003270 #
###                    ###

all: prog

prog: item.o ST.o main.o
	gcc -g -o prog item.o ST.o main.o

main.o: main.c 
	gcc -g -c main.c

ST.o: ST.c
	gcc -g -c ST.c

item.o: item.c
	gcc -g -c item.c

clean: 
	rm -f prog main.o ST.o item.o

run: prog
	./prog
