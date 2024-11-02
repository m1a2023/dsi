#include <iostream>
#include <cassert>

#include "./headers/LinkedList.h"
#include "./headers/Stack.h"
#include "./headers/Queue.h"
#include "./headers/FileReader.h"
#include "./headers/PostfixNotationReader.h"
#include "./headers/PostfixNotationTranslator.h"

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

    // Test: Peek last element
    assert(list.peek() == 2);

    // Test: Index of element
    assert(list.index_of(1) == 0);
    assert(list.index_of(2) == 1);

    // Edge case: Operations on empty list
    list.clear();
    try {
        list.pop();
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {
        // Expected exception
    }

    try {
        list.get(0);
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {
        // Expected exception
    }

    try {
        list.remove(0);
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {
        // Expected exception
    }

    try {
        list.to_string();
        assert(false); // Should not reach here
    } catch (const std::range_error&) {
        // Expected exception
    }

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

int main() {
    testLinkedList();
    testStack();
    testQueue();
    testFileReader();
    test_postfix_notation_reader();

    using namespace reader;
    std::vector<std::string> vec {"1", "+", "2", "*", "9", "sin", "1"};
    auto pnt = reader::postfix_notation_translator::in_vector(vec);
    auto v = pnt.get();

    for (auto p = v.begin(); p != v.end(); p++) {
        std::cout << *p << std::endl;
    }
    return 0;
}
