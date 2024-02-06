# Copyright [2024] <Gia Panchal>

CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic -g

LIB = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system

DEPS = FibLFSR.hpp PhotoMagic.hpp
OBJECTS = FibLFSR.o PhotoMagic.o main.o
PROGRAM = PhotoMagic

all: $(PROGRAM) test PhotoMagic.a

$(PROGRAM): $(OBJECTS) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

PhotoMagic.a: $(OBJECTS) $(DEPS)
	ar rcs $@ $(OBJECTS)

test: test.o FibLFSR.o PhotoMagic.o $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(PROGRAM) $(OBJECTS) test test.o PhotoMagic.a

lint:
	cpplint *.cpp *.hpp
