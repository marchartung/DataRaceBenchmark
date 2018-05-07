# Makefile for the StringBuffer bug

CXX ?= g++
CFLAGS +=-g
CXXFLAGS +=-g
LDFLAGS +=-lpthread

all: main

main: stringbuffer.o main.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -o main main.cpp stringbuffer.o $(LDFLAGS)

stringbuffer.o: stringbuffer.cpp stringbuffer.hpp
	$(CXX) $(CFLAGS) -c -o stringbuffer.o stringbuffer.cpp

clean:
	rm -f stringbuffer.o main
