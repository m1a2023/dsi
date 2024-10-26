#ifndef NODE_H
#define NODE_H

#include "Node.h"
#include "IDataStructure.h"

#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>

namespace dsi {
    
template <typename T>
class LinkedList {
public: 
    //constructor and destructor
    LinkedList();
    ~LinkedList();

    //core methods
    void        add(T item);
    void        push(T item);       
    void        insert(int index, T item);
    void        insert_first(T item);
    void        insert_last(T item);

    void        remove(int index);
    void        remove_first();     
    void        remove_last();      
    T           pop();   
    T           pop_first();           
    void        clear(); 
    
    T           get(int index);
    int         index_of(T item);
    T           peek();
    T           peek_first();

    int         size();
    bool        is_empty();
    
    std::string to_string();

private: 
    Node<T>*        head;
    Node<T>*        tail;
    int             list_size;
};
}

#include "../source/LinkedList.cpp"

#endif