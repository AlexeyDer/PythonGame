CFLAGS = -Wall -Werror 
OBJ = g++ -c $< -o $@ $(CFLAGS)
LIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

.PHONY: all clean

SOURCES = $(wildcard $(addprefix src/, *.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.h), $(addprefix build/, %.o), $(SOURCES))
EXECUTABLE = bin/main.exe

TEST_SOURCES = $(wildcard $(addprefix test/, *.cpp))
TEST_OBJECTS = $(patsubst $(addprefix test/, %.h),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.h))) $(patsubst $(addprefix test/, %.cpp),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.cpp)))
TEST_EXECUTABLE = bin/test.out

all: $(EXECUTABLE)
	
$(EXECUTABLE):  $(OBJECTS)
	g++ $^ -o $@ $(CFLAGS) $(LIBS) 

build/%.o: src/%.cpp
	$(OBJ)

clean:
	rm -f $(EXECUTABLE)  build/*.o


.PHONY: test

test: 
