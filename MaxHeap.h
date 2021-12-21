#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>

/* class of a max heap */
class MaxHeap {
   private:
    /* a stl vector that stores the elements of a max heap */
    std::vector<int> array;

   public:
    int parent(int i);

    int left_child_node(int i);

    int right_child_node(int i);

    int size_heap();

    bool is_empty();

    void heapify_down(int i);

    void heapify_up(int i);

    void add(int value);

    int max_element();

    void remove_max();
};

#endif /* MAXHEAP_H */
