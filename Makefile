# Makefile for twins project

twins: twins.o cld.o 
	gcc -o twins twins.o cld.o
twins.o: twins.c
	gcc -c twins.c
cld.o: cld.c
	gcc -c cld.c
sd.o: sd.c
	gcc -c sd.c
compare.o: compare.c
	gcc -c compare.c
clean:
	rm -f *.o twins a.out file.list
