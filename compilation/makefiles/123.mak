CC = gcc
XX = g++
CFLAGS = -Wall -O -g
TARGET = helloworld

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.cpp 
	$(XX) $(CFLAGS) -c $< -o $@

SOURCES =$(wildcard *.cpp)
OBJS =$(patsubst %.cpp, %.o, $(SOURCES))

$(TARGET): $(OBJS)
	$(XX) $(INC) $(OBJS) -o $(TARGET) 
clean:
	rm -rf *.o helloworld
