OBJS = $(wildcard src/*.cpp)
CC = g++
CFLAGS = -I$(CURDIR)/include -Wall -Wextra -Wno-unused-parameter
LFLAGS = -static-libstdc++
TARGET = ecs

all: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(CFLAGS) $(LFLAGS) -o $(TARGET)