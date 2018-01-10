CC = gcc
XX = g++
CFLAGS = -Wall -O -g
TARGET = main

%.o:%.cpp 
	$(XX) $(CFLAGS) -c $< -o $@

SOURCES =$(wildcard *.cpp)
OBJS =$(patsubst %.cpp, %.o, $(SOURCES))

$(TARGET): $(OBJS)
	$(XX) $(INC) $(OBJS) -o $(TARGET) 
clean:
	rm -rf *.o main
