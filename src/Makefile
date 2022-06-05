all : exec

construct.o : construct.c struct.h
	gcc -c construct.c -o construct.o

spe_of.o : spe_of.c struct.h
	gcc -c spe_of.c -o Spe_of.o

display.o : display.c struct.h
	gcc -c display.c -o display.o 

fight.o : fight.c spe_of.h display.h struct.h
	gcc -c fight.c -o fight.o

main.o : main.c struct.h construct.h fight.h display.h
	gcc -c main.c -o main.o

exec : main.o fight.o construct.o spe_of.o display.o 
	gcc $^ -o $@

clean :
	rm*.o
	rm exec