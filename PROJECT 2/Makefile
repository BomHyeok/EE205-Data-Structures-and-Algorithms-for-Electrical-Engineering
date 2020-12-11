C = g++

checker : checker.o
		$(C) -o checker checker.o 
checker.o : checker.cpp
		$(C) -c -o checker.o checker.cpp

gen : generator.o
		$(C) -o gen generator.o
gen.o : generator.cpp
		$(C) -c -o generator.o generator.cpp

merger : merger.o
		$(C) -o merger merger.o 
merger.o : merger.cpp
		$(C) -c -o merger.o merger.cpp

all : checker gen merger


clean :
	rm -f merger
	rm -f gen
	rm -f checker
	rm -f *.o
	rm -f *~
