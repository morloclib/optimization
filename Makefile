all:
	g++ -Wall -lboost_system -lm test.c optimization.hpp

clean:
	rm -f a.out *.o *.gch
