all:
	g++ -Wall -lgsl -lgslcblas -lm test.c optimization.h

clean:
	rm -f a.out *.o *.gch
