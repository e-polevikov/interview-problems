PROBLEM1=src/1/myxor.cpp
PROBLEM2=src/2/polyeval.cpp
PROBLEM3=src/3/rational.cpp

PROBLEMS=$(PROBLEM1) $(PROBLEM2) $(PROBLEM3)

all: 
	g++ $(PROBLEMS) tests/tests.cpp -o bin/tests.out

clean:
	rm bin/tests.out