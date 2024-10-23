#include "LinkedList.h"

template <typename T>
class Stack {
public:
    /// constructor and destructor 
    Stack();
    ~Stack();

    ///  core methods
    T           pop();
    void        push(T item);
    void        clear();
    bool        is_empty();
    T           peek();
    std::string to_string();

private:
    LinkedList<T>* list;
};

template <typename T>
Stack<T>::Stack() { this->list = new LinkedList<T>(); }

template <typename T>
Stack<T>::~Stack() { }

template <typename T>
T Stack<T>::pop() {
    if (list->is_empty()) 
        throw new std::out_of_range("Out of range exception.");
    
    return list->pop();
}

template <typename T>
void Stack<T>::push(T item) {
    this->list->push(item);
}

template <typename T>
void Stack<T>::clear() {
    this->list->clear();
}

template <typename T>
bool Stack<T>::is_empty() {
    return this->list->is_empty();
}

template <typename T>
T Stack<T>::peek() {
    return this->list->peek();
}

template <typename T>
std::string Stack<T>::to_string() {
    return this->list->to_string();
}