CC = g++
CFLAGS = -Wall -Werror
OBJ = g++ -c $< -o $@ $(CFLAGS)
LIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
LIBS_TEST = -lgtest -lgtest_main -pthread
.PHONY: all clean

SOURCES = $(wildcard $(addprefix src/, *.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.h), $(addprefix build/, %.o), $(SOURCES))
EXECUTABLE = bin/main.exe

TEST_SOURCES = $(wildcard $(addprefix test/, *.cpp)) $(wildcard $(addprefix src/, *.cpp)) $(wildcard $(addprefix src/, *.h))
TEST_OBJECTS = build/test.o build/binding.o
TEST_EXECUTABLE = bin/test.exe

GTEST_DIR = include/
USER_DIR = src/
GTEST_LIBS = libgtest.a libgtest_main.a


GTEST_LIB_DIR  = lib/
GTEST_HEADERS = -Iinclude/

all: $(EXECUTABLE)

$(EXECUTABLE):  $(OBJECTS)
	g++ $^ -o $@ $(CFLAGS) $(LIBS)

build/%.o: src/%.cpp
	$(OBJ)

clean:
	rm -f $(EXECUTABLE) $(TEST_EXECUTABLE)  build/*.o
.PHONY: test

test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(CFLAGS) $(LIBS_TEST) $(LIBS)  -o $@

build/%.o: test/%.cpp
	  g++ -c 	$(LIBS_TEST) $(CFLAGS) $(GTEST_HEADERS) $< -o $@
