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
TEST_OBJECTS = test/build/test.o test/build/binding.o
TEST_EXECUTABLE = bin/test.exe


all: $(EXECUTABLE)

$(EXECUTABLE):  $(OBJECTS)
	g++ $^ -o $@ $(CFLAGS) $(LIBS)

build/%.o: src/%.cpp
	$(OBJ)

clean:
	rm -f $(EXECUTABLE) $(TEST_EXECUTABLE)  build/*.o
	rm -rf test/build/
.PHONY: test

test: Folders $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) -Iinclude/gtest $(TEST_OBJECTS) $(CFLAGS) $(LIBS_TEST) $(LIBS)  -o $@

test/build/%.o: test/%.cpp
	g++ -c 	$(LIBS_TEST) $(CFLAGS) $< -o $@

test/build/%.o: src/%.cpp
	g++ -c 	$(LIBS_TEST) $(CFLAGS) $< -o $@

Folders:
	mkdir -p test/build/
