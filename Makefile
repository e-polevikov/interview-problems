PROBLEM1=1/myxor.cpp
PROBLEM2=2/polyeval.cpp
PROBLEM3=3/rational.cpp

PROBLEMS=$(PROBLEM1) $(PROBLEM2) $(PROBLEM3)

all: 
	g++ $(PROBLEMS) tests.cpp -o bin/tests.out

clean:
	rm bin/tests.out