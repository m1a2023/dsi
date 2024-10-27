#include "LinkedList.h"

namespace dsi {
template <typename T>
class Stack : public IDataStructure<T> {
public:
    //constructor and destructor 
    Stack();
    ~Stack();

    //core methods
    T               pop()           override;

    void            push(T item)    override;

    T               peek()          override;

    int             size()          override;
    void            clear()         override;
    bool            is_empty()      override;
    Stack<T>        copy()          const;

    std::string     to_string()     override;

private:
    LinkedList<T>* list;
};

template <typename T>
Stack<T>::Stack() { this->list = new LinkedList<T>(); }

template <typename T>
Stack<T>::~Stack() {
    this->list->clear();
    delete this->list;
}

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
int Stack<T>::size() {
    return this->list->size();
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

template <typename T>
Stack<T> Stack<T>::copy() const {
    Stack<T> stack;
    LinkedList<T> tmp_list;
    Node<T>* tmp_head_p = this->list->get_head();

    while (tmp_head_p != nullptr) {
        stack.push(tmp_head_p->data);
        tmp_head_p = tmp_head_p->next;
    }

    return stack;
}
}