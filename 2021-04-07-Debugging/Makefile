CXX=g++ -g
SANFLAGS= -Wall -fsanitize=address -fsanitize=undefined -fsanitize=leak
VALGRINDFLAGS=--tool=memcheck --track-origins=yes --leak-check=full

all: a.out

a.out: array_bounds.cpp
	$(CXX) $(SANFLAGS) $<

valgrind: array_bounds.cpp
	$(CXX)  $<
	valgrind $(VALGRINDFLAGS) ./a.out &>log.txt

clean: a.out
	rm -f a.out log.txt
