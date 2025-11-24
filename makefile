CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: main

main: lab13.cpp
	$(CXX) $(CXXFLAGS) lab13.cpp -o lab13

clean:
	rm -f main
