#include <iostream>
#include "./headers/LinkedList.h"
#include "./headers/Stack.h"
#include "headers/Queue.h"

int main() {
    LinkedList<int> list;

    //testing
    {
//works correclty
    for (int i = 0; i < 10; i++) {
        list.add(i);
    }
    
//works correctly
    //list.remove(0);

//works correctly
    std::cout 
        << std::endl 
        << "items: " << list.to_string() 
        << std::endl 
        << "size: " << list.size() 
        << std::endl 
        << "is empty? " << list.is_empty()
        << std::endl;

    LinkedList<std::string> list1;

//workds correctly
    std::cout 
        << std::endl 
        << "items: " << list.to_string() 
        << std::endl;

//workds correctly
    list.insert_first(-1);
    std::cout << "\ninsert_first(-1)\n";
    list.insert(4, 999);
    std::cout << "\ninsert(4, 999)\n";
    list.insert_last(-9);
    std::cout << "\ninsert_last(-9)\n";

    list.remove_first();
    std::cout << "\nremove_first()\n";
    list.remove_last();
    std::cout << "\nremove_last()\n";

    std::cout 
        << std::endl << "items: " << list.to_string() << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << "list.pop: " << list.pop() << std::endl;
    }

    std::cout 
        << std::endl << "items: " << list.to_string() << std::endl;
    
    std::cout 
        << std::endl << "peek(): " << list.peek() << std::endl;
    }
    
    std::cout << "\n-------------------------------\n";

    Stack<std::string> stack;
    //testing
    {
    for (int i = 0; i < 21; i += 2) {
        stack.push(std::to_string(i) + "<-string");
    }

    std::cout << std::endl << stack.to_string() << std::endl; 
    std::cout << std::endl << stack.peek() << std::endl; 
    }

    std::cout << "\n-------------------------------\n";

    Queue<std::string> queue;
    //testing
    {
        for (int i = 0; i < 21; i += 2) {
            queue.push(std::to_string(i) + "<-string");
        }

        std::cout << std::endl << queue.to_string() << std::endl;
        std::cout << std::endl << queue.peek() << std::endl;
    }
    int j;
    std::cin >> j;
    return 0;
   
}
