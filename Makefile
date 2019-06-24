OBJS = $(wildcard src/*.cpp)
OBJS_OTHER = $(wildcard src/*.cpp) $(wildcard example/src/*.cpp)
CC = g++
INCLUDE_PATHS = -I$(CURDIR)/include -I$(CURDIR)/example/include
CFLAGS = -Wall -Wextra -Wno-unused-parameter
LFLAGS = -static-libstdc++
TARGET = blargh

all: $(OBJS_OTHER)
	$(CC) $(OBJS_OTHER) $(INCLUDE_PATHS) $(CFLAGS) $(LFLAGS) -o $(TARGET)

lib: $(OBJS)
	$(CC) -fPIC $(OBJS) $(INCLUDE_PATHS) $(CFLAGS) -shared -o lib$(TARGET).dll