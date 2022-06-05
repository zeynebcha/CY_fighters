all : exec

construct.o : construct.c struct.h
	gcc -c construct.c -o construct.o

Spe_off.o : Spe_off.c struct.h
	gcc -c Spe_off.c -o Spe_off.o

display.o : display.c struct.h
	gcc -c display.c -o display.o 

combat.o : Combat.c Spe_off.h display.h struct.h
	gcc -c Combat.c -o combat.o

main.o : main.c struct.h construct.h combat.h
	gcc -c main.c -o main.o

exec : main.o combat.o construct.o Spe_off.o display.o 
	gcc $^ -o $@

clean :
	rm*.o
	rm exec