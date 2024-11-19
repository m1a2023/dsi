#pragma once

#include <queue>
#include <IDataStructure.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/fmt/ranges.h>
#include <vector>
#include <string>

namespace dsi {
template <typename T>
class _inner_queue : public IDataStructure<T> {

public:
    _inner_queue();
    ~_inner_queue();

    T               pop()           override;

    void            push(T item)    override;

    T               peek()          override;

    int             size()          override;
    void            clear()         override;
    bool            is_empty()      override;
    std::queue<T>   copy();

    std::string     to_string()     override;

private:
    std::queue<T>   _queue;
    int             _size;
};
}

template <typename T>
dsi::_inner_queue<T>::_inner_queue() { this->_size = 0; }

template <typename T>
dsi::_inner_queue<T>::~_inner_queue() { }

template <typename T>
T dsi::_inner_queue<T>::pop() {
    if (this->_queue.empty()) {
        throw std::out_of_range("Queue is empty!");
    }

    T tmp = this->_queue.front();
    this->_queue.pop();
    this->_size--;

    return tmp;
}

template <typename T>
void dsi::_inner_queue<T>::push(T item) {
    this->_queue.push(item);
    this->_size++;
}

template <typename T>
T dsi::_inner_queue<T>::peek() {
    if (this->_queue.empty()) {
        throw std::out_of_range("Queue is empty!");
    }

    return this->_queue.front();
}

template <typename T>
int dsi::_inner_queue<T>::size() {
    return _size;
}

template <typename T>
void dsi::_inner_queue<T>::clear() {
    while (!this->_queue.empty()) {
        this->_queue.pop();
    }

    this->_size = 0;
}

template <typename T>
bool dsi::_inner_queue<T>::is_empty() {
    return this->_queue.empty();
}

template <typename T>
std::queue<T> dsi::_inner_queue<T>::copy() {
    std::queue<T> copyQueue = this->_queue;
    return copyQueue;
}

template <typename T>
std::string dsi::_inner_queue<T>::to_string() {
    if (!this->_size) {
        throw std::out_of_range("Out of range exception, thrown by _inner_queue");
    }

    std::queue<T> _tmp_queue = this->copy();
    std::stringstream ss;

    while (!_tmp_queue.empty()) {
        ss << _tmp_queue.front() << " ";
        _tmp_queue.pop();
    }

    ss << std::endl;

    return ss.str();
}
