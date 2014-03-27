CXX=g++
CFLAGS=
LDFLAGS=-lglpk -lm
EXEC=Main

SRC=$(wildcard *.cpp )
OBJ=$(SRC:.cpp=.o)

all:$(EXEC)

Main:$(OBJ)
	$(CXX) -o main $^ $(LDFLAGS)

%.o: %.cpp
	@$(CXX) -std=c++0x -o $@ -c $< $(CFLAGS)
	
.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
