#include "MaxHeap.h"

/* the function that returns the parent of an element */
int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

/* the function that returns the left child of an element */
int MaxHeap::left_child_node(int i) {
    return (2 * i + 1);
}

/* the function that returns the right child of an element */
int MaxHeap::right_child_node(int i) {
    return (2 * i + 2);
}

/* the function that returns the size of the heap */
int MaxHeap::size_heap() {
    return array.size();
}

/* the function that checks if the heap is empty */
bool MaxHeap::is_empty() {
    if (MaxHeap::size_heap() == 0) {
        return true;
    }
    return false;
}

/* a recursive method to heapify down a subtree with the root at given index */
void MaxHeap::heapify_down(int i) {
    /* get the right and left child of the node */
    int right_child = right_child_node(i);
    int left_child = left_child_node(i);

    int great_node = i;
    /* find the greater value of the left and right child */
    if (right_child < size_heap() && array[right_child] > array[i]) {
        great_node = right_child;
    }

    if (left_child < size_heap() && array[left_child] > array[great_node]) {
        great_node = left_child;
    }
    /* the exchange of elements that do not respect the desired order */
    if (great_node != i) {
        std::swap(array[great_node], array[i]);
        heapify_down(great_node);
    }
}

/* a recursive method to heapify up a subtree */
void MaxHeap::heapify_up(int i) {
    int parent_node = parent(i);
    if (array[parent_node] < array[i]) {
        std::swap(array[parent_node], array[i]);
        heapify_up(parent_node);
    }
}

/* the function that adds a new value to the heap */
void MaxHeap::add(int value) {
    array.push_back(value);
    int index_size = array.size() - 1;
    heapify_up(index_size);
}

/* the function that returns the top element(max element) */
int MaxHeap::max_element() {
    if (!is_empty()) {
        return array[0];
    }
    return -1;
}

/* the function that removes the top element(max element) */
void MaxHeap::remove_max() {
    if (!is_empty()) {
        int value = array.back();
        array[0] = value;
        array.pop_back();
        heapify_down(0);
    }
}
