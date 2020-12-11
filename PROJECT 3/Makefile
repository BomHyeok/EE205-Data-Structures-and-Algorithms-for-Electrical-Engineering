XX	= g++


tester : tester.o bst.o
		$(CXX) -o tester tester.o bst.o
tester.o : tester.cpp
		$(CXX) -c -o tester.o tester.cpp

tester_private : tester_private.o bst.o
		$(CXX) -o tester_private tester_private.o bst.o
tester_private.o : tester_private.cpp 
		$(CXX) -c -o tester_private.o tester_private.cpp

bst.o : bst.cpp
		$(CXX) -c -o bst.o bst.cpp


all : tester tester_private


clean :
		rm -f tester_private	
		rm -f tester
		rm -f *.o
		rm -f *~
