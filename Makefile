./project:main.o tail_test.o head_test.o
	cc *.o -o project
main.o: main.c head_test.h tail_test.h 
	cc  -c main.c -Wall
tail_test.o: tail_test.c tail_test.h
	cc  -c tail_test.c -Wall
head_test.o: head_test.c head_test.h
	cc  -c head_test.c -Wall

