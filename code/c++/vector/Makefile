
COMPILER = g++
FLAGS = -D_DEBUG

all:
	$(COMPILER) $(FLAGS) Vector.cpp -c -o Vector.o
	$(COMPILER) $(FLAGS) Matrix.cpp -c -o Matrix.o
	$(COMPILER) $(FLAGS) main.cpp Vector.o Matrix.o

test: all
	./a.out

clean:
	rm *~ *.o
