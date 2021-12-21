/* Test for HEAP Algorithm checker */
#include <bits/stdc++.h>

#include "MaxHeap.h"

#define SIZE_NAME_TEST 30

int main(void) {
    /* creating the input file */
    char input_name[SIZE_NAME_TEST];
    sprintf(input_name, "./test.in");
    std::ifstream input_file(input_name);

    char output_name[SIZE_NAME_TEST];
    sprintf(output_name, "./test.out");
    std::ofstream output_file(output_name);

    /* creating a max heap and running the algorithm based on commands */
    MaxHeap heap;
    while (!input_file.eof()) {
        std::string command;
        input_file >> command;
        if (command == "push") {
            int value;
            input_file >> value;
            heap.add(value);
        } else if (command == "pop") {
            heap.remove_max();
        } else if (command == "top") {
            /* displaying the result in the test.out folder */
            output_file << heap.max_element() << "\n";
        }
    }
    /* close the files */
    input_file.close();
    output_file.close();
    return 0;
}
