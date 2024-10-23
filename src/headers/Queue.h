#include "LinkedList.h"

template <typename  T> 
class Queue
{
public:

    Queue();
    ~Queue();

	void			push(T item);
	T				pop();
	bool			is_empty();
	T				peek();
	std::string		to_string();

private:
	LinkedList<T>* list;
};

template <typename T>
Queue<T>::Queue() { this->list = new LinkedList<T>(); }

template <typename T>
Queue<T>::~Queue() { }

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
bool Queue<T>::is_empty() {
    return this->list->is_empty();
}

template <typename T>
T Queue<T>::peek() {
    return this->list->peek();
}

template <typename T>
std::string Queue<T>::to_string() {
    return this->list->to_string();
}