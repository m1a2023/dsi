#include <iostream>
#include <cassert>
#include <random>

#include "./headers/LinkedList.h"
#include "./headers/Stack.h"
#include "./headers/Queue.h"
#include "./headers/FileReader.h"
#include "./headers/PostfixNotationReader.h"
#include "./headers/PostfixNotationTranslator.h"
#include "./headers/StackCalculation.h"
#include "./headers/TimeMeasurer.h"
#include "./headers/StackCalculation.h"
#include "./headers/Tree.h"
#include "./headers/InnerStack.hpp"
#include "./headers/InnerQueue.hpp"
#include "./headers/TimeMeasurerController.hpp"

#define     POSTFIX_NOTATION_READER_TEST_FILE   "/home/mia/dev/csu/algo/dsi/postfix-notation-reader-demo-input.txt"
#define     TIME_MEASURER_OUTPUT_FILE           "./all-times.txt"


#ifdef DEBUG
void testLinkedList() {
    LinkedList<int> list;

    // Test: Initial state
    assert(list.size() == 0);
    assert(list.is_empty());

    // Test: Adding elements
    list.add(1);
    list.add(2);
    list.add(3);
    assert(list.size() == 3);
    assert(list.to_string() == "1 2 3 ");

    // Test: Insert at specific positions
    list.insert(1, 10);  // Insert 10 at index 1
    assert(list.to_string() == "1 10 2 3 ");
    list.insert_first(0);
    assert(list.to_string() == "0 1 10 2 3 ");
    list.insert_last(99);
    assert(list.to_string() == "0 1 10 2 3 99 ");
    assert(list.size() == 6);

    // Test: Retrieve elements
    assert(list.get(0) == 0);
    assert(list.get(2) == 10);
    assert(list.get(5) == 99);

    // Test: Remove elements
    list.remove(0); // Remove first element
    assert(list.to_string() == "1 10 2 3 99 ");
    list.remove_first();
    assert(list.to_string() == "10 2 3 99 ");
    list.remove_last();
    assert(list.to_string() == "10 2 3 ");
    assert(list.size() == 3);

    // Test: Clear the list
    list.clear();
    assert(list.is_empty());
    assert(list.size() == 0);

    // Test: Pop elements (add first to populate)
    list.add(1);
    list.add(2);
    list.add(3);
    assert(list.pop() == 3);
    assert(list.to_string() == "1 2 ");
    assert(list.size() == 2); 

    std::cout << "All LinkedList tests passed successfully!" << std::endl;
}

void testStack() {
    Stack<int> stack;
    // Basic push
    for (int i = 0; i < 5; ++i) stack.push(i);
    assert(stack.size() == 5);

    // Peek and pop
    assert(stack.peek() == 4);
    for (int i = 4; i >= 0; --i) {
        assert(stack.pop() == i);
    }
    assert(stack.is_empty());

    // Edge case
    try {
        stack.pop();
        assert(false); // Should not reach here
    } catch (...) {
        assert(true); // Expecting exception
    }
}

void testQueue() {
    Queue<int> queue;
    // Basic enqueue
    for (int i = 0; i < 5; ++i) queue.push(i);
    assert(queue.size() == 5);

    // Peek and dequeue
    assert(queue.peek() == 0);
    for (int i = 0; i < 5; ++i) {
        assert(queue.pop() == i);
    }
    assert(queue.is_empty());

    // Edge case
    try {
        queue.pop();
        assert(false); // Should not reach here
    } catch (...) {
        assert(true); // Expecting exception
    }
}

void testFileReader() {
    Queue<std::string> queue;
    Stack<std::string> stack;
    reader::FileReader<std::string> reader("/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/input.txt");
    reader.process_file(&queue);
    reader.process_file(&stack);
}

void test_postfix_notation_reader() {
    using namespace reader;

    // Prepare test file
    const std::string test_file = "test_input.txt";
    std::ofstream test_stream(test_file);
    assert(test_stream.is_open());
    test_stream << "3 4 + 5 * 6 -"; // Expected data in the file
    test_stream.close();

    // Test in_file method
    postfix_notation_reader reader = postfix_notation_reader::in_file(test_file);
    
    // Test get method
    std::vector<std::string> result = postfix_notation_reader::get();
    
    // Expected output after splitting
    std::vector<std::string> expected = {"3", "4", "+", "5", "*", "6", "-"};

    // Check if the result matches the expected output
    assert(result == expected);

    // Clean up test file
    std::remove(test_file.c_str());

    std::cout << "Test passed!" << std::endl;
}

void test_postfix_notation_translator() {
    // Test case 1: Simple arithmetic expression
    std::vector<std::string> input1 = {"3", "+", "4"};
    auto translator = reader::postfix_notation_translator::in_vector(input1);
    auto result1 = translator.get();
    auto exp = std::vector<std::string>{"3", "4", "+"};
    assert(result1 == exp);
    std::cout << "Test case 1 passed." << std::endl;
    
    // Test case 2: Order of operations
    std::vector<std::string> input2 = {"3", "+", "4", "*", "2"};
    translator.in_vector(input2);
    auto result2 = translator.get();
    exp = {"3", "4", "2", "*", "+"};
    assert(result2 == exp);
    std::cout << "Test case 2 passed." << std::endl;

    // Test case 3: Parentheses
    std::vector<std::string> input3 = {"(", "3", "+", "4", ")", "*", "2"};
    translator.in_vector(input3);
    auto result3 = translator.get();
    exp = {"3", "4", "+", "2", "*"};
    assert(result3 == exp);
    std::cout << "Test case 3 passed." << std::endl;

    // Test case 4: Exponents and unary functions
    std::vector<std::string> input4 = {"sin", "(", "30", ")", "+", "2", "^", "3"};
    translator.in_vector(input4);
    auto result4 = translator.get();
    exp = {"30", "sin", "2", "3", "^", "+"};
    assert(result4 == exp);
    std::cout << "Test case 4 passed." << std::endl;

    // Test case 5: Mixed operations
    std::vector<std::string> input5 = {"(", "3", "+", "4", ")", "*", "(", "2", "-", "1", ")"};
    translator.in_vector(input5);
    auto result5 = translator.get();
    exp = {"3", "4", "+", "2", "1", "-", "*"};
    assert(result5 == exp);
    std::cout << "Test case 5 passed." << std::endl;

    // Test case 6: Unary operation
    std::vector<std::string> input6 = {"cos", "(", "0", ")", "*", "2"};
    translator.in_vector(input6);
    auto result6 = translator.get();
    exp = {"0", "cos", "2", "*"};
    assert(result6 == exp);
    std::cout << "Test case 6 passed." << std::endl;

    std::cout << "All test cases passed!" << std::endl;
}

void test_time_measurer() {
    // Create a mock data structure and wrap it in a TimeMeasurer
    //auto data_structure = new Stack<int>();
    dsi::TimeMeasurer<int> time_measurer(new Stack<int>());

    // Test push
    time_measurer.push(42);
    std::cout << "Push test passed." << std::endl;

    // Test peek
    int peeked = time_measurer.peek();
    std::cout << "Peek test result: " << peeked << std::endl;

    // Test pop
    int popped = time_measurer.pop();
    std::cout << "Pop test result: " << popped << std::endl;

    // Test size
    int size = time_measurer.size();
    std::cout << "Size test result: " << size << std::endl;

    // Test clear
    // time_measurer.clear();
    // std::cout << "Clear test passed." << std::endl;

    // Test is_empty
    bool empty = time_measurer.is_empty();
    std::cout << "Is empty test result: " << (empty ? "true" : "false") << std::endl;

    // Test to_string
    // std::string str = time_measurer.to_string();
    //std::cout << "To string test result: " << str << std::endl;

    // Test in_general and in_vector timing methods
    long double total_time = time_measurer.in_general();
    std::cout << "Total execution time in general: " << total_time << " seconds" << std::endl;

    std::vector<long double> individual_times = time_measurer.in_vector();
    std::cout << "Individual execution times: ";
    for (const auto& time : individual_times) {
        std::cout << time << " ";
    }
    std::cout << std::endl;

    std::cout << "All tests completed successfully." << std::endl;
}

void test_tree() {
        try {
        // Create a tree of integers
        dsi::tree<int> intTree;

        // Add elements to the tree
        intTree.add(10, dsi::tree<int>::LEFT);
        intTree.add(20, dsi::tree<int>::RIGHT);

        // Check if an element exists
        if (intTree.contains(10)) {
            std::cout << "10 is in the tree.\n";
        } else {
            std::cout << "10 is not in the tree.\n";
        }

        if (intTree.contains(15)) {
            std::cout << "15 is in the tree.\n";
        } else {
            std::cout << "15 is not in the tree.\n";
        }

        // Perform in-order traversal
        std::cout << "In-order Traversal:\n";
        intTree.in_order_traversal();

        // Perform pre-order traversal
        std::cout << "Pre-order Traversal:\n";
        intTree.pre_order_traversal();

        // Perform post-order traversal
        std::cout << "Post-order Traversal:\n";
        intTree.post_order_traversal();

        // Remove an element
        std::cout << "Removing 10 from the tree.\n";
        intTree.remove(10);

        // Check size and depth
        std::cout << "Tree size: " << intTree.size() << "\n";
        std::cout << "Tree depth: " << intTree.depth() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

}
#endif

int main() {
    // std::vector<std::string> _vec;
    // std::vector<std::string> _vec1;
    
    // reader::postfix_notation_reader::in_file(POSTFIX_NOTATION_READER_TEST_FILE);
    // _vec = reader::postfix_notation_reader::get();

    // reader::postfix_notation_translator::in_vector(_vec);
    // _vec1 = reader::postfix_notation_translator::get();

    // auto out = dsi::stack_calc<double>::calculate(_vec1);
    // std::cout << out << std::endl;

    
    dsi::_time_measurer_controller<int> tmc (
        std::vector<std::shared_ptr<TimeMeasurer<int>>> { 
            std::make_shared<TimeMeasurer<int>>(new Stack<int>), 
            std::make_shared<TimeMeasurer<int>>(new Queue<int>),
            std::make_shared<TimeMeasurer<int>>(new _inner_stack<int>),
            std::make_shared<TimeMeasurer<int>>(new _inner_queue<int>)
        }
    );

    for (int i = 0; i < 100; i++) {
        tmc.push(std::rand());
    }

    tmc.to_file(TIME_MEASURER_OUTPUT_FILE);

    return  0;
}

