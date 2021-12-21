/* Checker for AVL Algorithm */
#include <bits/stdc++.h>

#include "AVL.h"

#define NUMBER_TESTS 23
#define SIZE_NAME_TEST 30

/* https://stackoverflow.com/questions/15118661/in-c-whats-the-
 * fastest-way-to-tell-whether-two-string-or-binary-files-are-di
 */
template <typename InputIterator1, typename InputIterator2>
bool range_equal(InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, InputIterator2 last2) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 != *first2) return false;
        ++first1;
        ++first2;
    }
    return (first1 == last1) && (first2 == last2);
}

bool compare_files(const std::string& filename1, const std::string& filename2) {
    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    std::istreambuf_iterator<char> end;

    return range_equal(begin1, end, begin2, end);
}

int main(void) {
    std::cout << "Checker tests AVL Algorithm:\n";

    /* running the checker for each test */
    for (int i = 1; i <= NUMBER_TESTS; ++i) {
        /* start time monitoring */
        auto start = std::chrono::high_resolution_clock::now();

        /* creating the necessary files */
        char input_name[SIZE_NAME_TEST];
        sprintf(input_name, "./in/test%d.in", i);
        std::ifstream input_file(input_name);

        char output_name[SIZE_NAME_TEST];
        sprintf(output_name, "./test_out/p2/test%d.out", i);
        std::ofstream output_file(output_name);

        char ref_name[SIZE_NAME_TEST];
        sprintf(ref_name, "./out/p2/test%d.out", i);
        std::ifstream ref_file(ref_name);

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
                /* displaying the result in the test_outfolder */
                output_file << avl.max_element() << "\n";
            }
        }
        /* close the files */
        input_file.close();
        output_file.close();
        ref_file.close();
        /* checking the contents of the two files out / test_out */
        if (compare_files(output_name, ref_name) == true) {
            std::cout << "TEST " << i << " PASSED\n";
        } else {
            std::cout << "TEST " << i << " FAILED\n";
        }
        /* end time monitoring */
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        /* displaying the execution of the test in time */
        std::cout << "Execution time : " << duration << " microseconds\n";
    }
}
