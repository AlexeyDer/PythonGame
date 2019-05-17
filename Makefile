CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)
LIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

.PHONY: all clean

SOURCES = $(wildcard $(addprefix src/, *.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.h), $(addprefix build/, %.o), $(SOURCES))
EXECUTABLE = bin/main.exe

TEST_SOURCES = $(wildcard $(addprefix test/, *.cpp))
TEST_OBJECTS_SRC = $(patsubst $(addprefix test/, %.h),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.h)))
TEST_OBJECTS_TEST = $(patsubst $(addprefix test/, *.cpp),$(addprefix build/, %.o), $(TEST_SOURCES))
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

 $(TEST_EXECUTABLE): $(TEST_OBJECTS_SRC) $(TEST_OBJECTS_TEST)
	$(OBJ)

build/%test.o: src/%.cpp
	$(OBJ)

build/%.o : test/%.cpp
	$(OBJ)	


