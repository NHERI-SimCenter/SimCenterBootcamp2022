
# COMPILER = icc
COMPILER = clang
FLAGS = -D_DEBUG

all:
	$(COMPILER) $(FLAGS) Shape.cpp -c -o Shape.o
	$(COMPILER) $(FLAGS) Rectangle.cpp -c -o Rectangle.o
	$(COMPILER) $(FLAGS) Circle.cpp -c -o Circle.o
	$(COMPILER) $(FLAGS) Square.cpp -c -o Square.o
	$(COMPILER) $(FLAGS) main1.cpp Shape.o Rectangle.o Circle.o Square.o

test: all
	./a.out

clean:
	rm *~ *.o
