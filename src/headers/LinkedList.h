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
    void            add(T item);
    void            push(T item);       
    void            insert(int index, T item);
    void            insert_first(T item);
    void            insert_last(T item);
    LinkedList<T>   copy() const;

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
    Node<T>*    get_head();     

    int         size();
    bool        is_empty();
    
    std::string to_string();

    //additional methods
    void        reverse();
    void        ftol(); //first to last
    void        ltof(); //last to first
    int         qint(); //quantity integers
    void        set();
    void        insert_its(int index); //insert itself at index
    void        instoasc(T item); // insert element to sorted by ascend list
    void        remove_by_item(T item);
    void        remove_each_item(T item);
    void        insbefore(T el, T next);
    void        add(); //itself
    void        add(LinkedList<T> list); //another
    void        splitby(T item); 
    void        replace(T a, T b);

private: 
    Node<T>*        head;
    Node<T>*        tail;
    int             list_size;
};
}

#include "../source/LinkedList.cpp"

#endif