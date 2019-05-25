CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)
LIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
LIBS_TEST = -lgtest -lgtest_main
.PHONY: all clean

SOURCES = $(wildcard $(addprefix src/, *.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.h), $(addprefix build/, %.o), $(SOURCES))
EXECUTABLE = bin/main.exe

TEST_OBJECTS = test/test.o
TEST_EXECUTABLE = bin/test.exe

all: $(EXECUTABLE)
	
$(EXECUTABLE):  $(OBJECTS)
	g++ $^ -o $@ $(CFLAGS) $(LIBS) 

build/%.o: src/%.cpp
	$(OBJ)

clean:
	rm -f $(EXECUTABLE)  build/*.o 


.PHONY: test

test: $(TEST_EXECUTABLE)
	 $(TEST_EXECUTABLE)

 $(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(OBJ)

$(TEST_OBJECTS): test/test.cpp
	g++ src/binding.h test/test.cpp $(LIBS_TEST) -o build/test.o




