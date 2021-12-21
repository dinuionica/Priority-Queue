CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: test_heap.o test_avl.o

run-best:
	./test_heap

run-p1:
	./test_heap

run-p2:
	./test_avl

MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ MaxHeap.cpp MaxHeap.h -c $(CFLAGS)

test_heap.o: test_heap_algo.cpp MaxHeap.o
	g++ MaxHeap.o test_heap_algo.cpp -o test_heap $(CFLAGS)

AVL.o: AVL.cpp AVL.h
	g++ AVL.cpp AVL.h -c $(CFLAGS)

test_avl.o: test_avl_algo.cpp AVL.o
	g++ AVL.o test_avl_algo.cpp -o test_avl $(CFLAGS)

checker-avl-cpp:
	g++ checker_avl_algo.cpp AVL.cpp AVL.h -o c_avl && ./c_avl

checker-heap-cpp:
	g++ checker_heap_algo.cpp MaxHeap.cpp MaxHeap.h -o c_heap && ./c_heap
	
.PHONY: clean

clean:
	rm -rf *.o  *.h.gch  test_heap test_avl test.in test.out a.out c_heap c_avl
