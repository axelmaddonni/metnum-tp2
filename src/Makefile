CXX= g++
CXXFLAGS= -std=c++11 -g -Wfatal-errors
DEPS= header.h
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

make: $(OBJECTS) header.h
	$(CXX) -o main $(OBJECTS) header.h $(CXXFLAGS)

clean:
	rm -f *.o main

test:
	make clean && python metnum.py test && python metnum.py clean

testMio:
	make clean && make && ./main tests/testMio.in tests/testMio.out

test1:
	make clean && make && ./main tests/test1.in tests/test1.out

debug:
	make clean && make && gdb --args ./main tests/testMio2.in tests/testMio2.out tests/testMio2.pers
	
testPers:
	make clean && make && ./main tests/testMio2.in tests/testMio2.out tests/testMio2.pers && ./main tests/testMio2.in tests/testMio2.out
