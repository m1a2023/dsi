#include "LinkedList.h"

namespace dsi { 
template <typename T> 
class Queue : public IDataStructure<T> {
public:
    //constructor and destructor 
    Queue();
    ~Queue();

    //core methods
    T               pop()           override;
    
    void            push(T item)    override;

    T               peek()          override;

    int             size()          override;
    void            clear()         override;
    bool            is_empty()      override;
    Queue<T>        copy()          const;

    std::string     to_string()     override;

private:
	LinkedList<T>* list;
};

template <typename T>
Queue<T>::Queue() { this->list = new LinkedList<T>(); }

template <typename T>
Queue<T>::~Queue() {
    this->list->clear();
    delete this->list;
}

template <typename T>
T Queue<T>::pop() {
    if (list->is_empty())
        throw new std::out_of_range("Out of range exception.");

    return list->pop();
}

template <typename T>
void Queue<T>::push(T item) {
    this->list->insert_first(item);
}

template <typename T>
int Queue<T>::size() {
    return this->list->size();
}

template <typename T>
bool Queue<T>::is_empty() {
    return this->list->is_empty();
}

template <typename T>
void Queue<T>::clear() {
    this->list->clear();
}

template <typename T>
T Queue<T>::peek() {
    return this->list->peek();
}

template <typename T>
std::string Queue<T>::to_string() {
    return this->list->to_string();
}

template <typename T>
Queue<T> Queue<T>::copy() const {
    Queue<T> queue;
    LinkedList<T> tmp_list;
    Node<T>* tmp_head_p = this->list->get_head();

    while (tmp_head_p != nullptr) {
        tmp_list.add(tmp_head_p->data);
        tmp_head_p = tmp_head_p->next;
    }

    while (!tmp_list.is_empty()) {
        queue.push(tmp_list.pop());
    }

    return queue;
}
}