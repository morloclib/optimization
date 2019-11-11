all:
	g++ -Wall -lgsl -lgslcblas -lm test.c optimization.hpp

clean:
	rm -f a.out *.o *.gch
