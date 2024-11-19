#pragma once

#include <stack>
#include <IDataStructure.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/fmt/ranges.h>
#include <vector>
#include <string>

namespace dsi {
template <typename T>
class _inner_stack : public IDataStructure<T>{

public:
    _inner_stack();
    ~_inner_stack();

    //core methods
    T               pop()           override;

    void            push(T item)    override;

    T               peek()          override;

    int             size()          override;
    void            clear()         override;
    bool            is_empty()      override;
    std::stack<T>   copy();

    std::string     to_string()     override;

private:
    std::stack<T>   _stack;
    int             _size;
};
}

template <typename T>
dsi::_inner_stack<T>::_inner_stack() { this->_size = 0; }

template <typename T>
dsi::_inner_stack<T>::~_inner_stack() { }

template <typename T>
T dsi::_inner_stack<T>::pop() {
    T tmp = this->_stack.top();

    this->_size--;
    this->_stack.pop();

    return tmp;
}

template <typename T>
void dsi::_inner_stack<T>::push(T item) {
    this->_stack.push(item);
    this->_size++;
}

template <typename T>
T dsi::_inner_stack<T>::peek() {
    return this->_stack.top();
}

template <typename T>
int dsi::_inner_stack<T>::size() {
    return _size;
}

template <typename T>
void dsi::_inner_stack<T>::clear() {
    while (!this->_stack.empty()) {
        this->_stack.top();
    }
    
    this->_size = 0;
    
    return;
}

template <typename T>
bool dsi::_inner_stack<T>::is_empty() {
    return this->_stack.empty();
}

template <typename T>
std::stack<T>
dsi::_inner_stack<T>::copy() {
    std::stack<T> _tmp_stack = this->_stack;
    return _tmp_stack; 
}

template <typename T>
std::string
dsi::_inner_stack<T>::to_string() {
    if (!this->_size) {
        throw std::out_of_range("Out of range exception, thrown by _inner_stack");
    }

    std::stack<T> _tmp_stack = this->copy();
    std::stringstream ss;

    while (!_tmp_stack.empty()) {
        ss << _tmp_stack.top() << " ";
        _tmp_stack.pop();
    } 

    ss << std::endl;

    return ss.str();
}
