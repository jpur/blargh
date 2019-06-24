OBJS = $(wildcard src/*.cpp) $(wildcard src/ex/*.cpp)
CC = g++
CFLAGS = -I$(CURDIR)/include -Wall -Wextra -Wno-unused-parameter
LFLAGS = -static-libstdc++ -lSDL2main -lSDL2
TARGET = ecs

all: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(CFLAGS) $(LFLAGS) -o $(TARGET)

lib: $(OBJS)
	$(CC) -fPIC $(OBJS) $(CFLAGS) -shared -o libecs.dll