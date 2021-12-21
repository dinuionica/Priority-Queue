/* Test checker for AVL Algorithm */
#include <bits/stdc++.h>

/* Test for AVL Algorithm checker */
#include "AVL.h"

#define SIZE_NAME_TEST 30

int main(void) {
    /* creating the input file */
    char input_name[SIZE_NAME_TEST];
    sprintf(input_name, "./test.in");
    std::ifstream input_file(input_name);

    /* creating the input file */
    char output_name[SIZE_NAME_TEST];
    sprintf(output_name, "./test.out");
    std::ofstream output_file(output_name);

    /* creating an avl and running the algorithm based on commands */
    AVL avl;
    while (!input_file.eof()) {
        std::string command;
        input_file >> command;
        if (command == "push") {
            int value;
            input_file >> value;
            avl.add(value);
        } else if (command == "pop") {
            avl.remove_max();
        } else if (command == "top") {
            /* displaying the result in the test.out folder */
            output_file << avl.max_element() << "\n";
        }
    }
    /* close the files */
    input_file.close();
    output_file.close();
    return 0;
}
