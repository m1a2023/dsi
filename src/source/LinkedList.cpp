#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../headers/LinkedList.h"

using namespace dsi;

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->list_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() { this->clear(); }

template <typename T> 
void LinkedList<T>::add(T item) {
    Node<T>* node = new Node<T> (item);

    if (this->head == nullptr) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
    this->list_size++;

    return;
}

template <typename T>
void LinkedList<T>::push(T item) {
    this->add(item);
    return;
}

template <typename T>
T LinkedList<T>::get(int index) {
    if (this->head == nullptr || index < 0 || index > this->list_size) 
        throw std::out_of_range("Out of range exception.");
        Node<T>* tmp = this->head;

    for (int i = 0; i < index; i++) {
        if (tmp->next == nullptr) {
            throw std::out_of_range("Out of range exception.");
        }
        tmp = tmp->next;
    }

    return tmp->data;
}

template <typename T> 
void LinkedList<T>::insert(int index, T item) {
    Node<T>* new_last_node = new Node<T> (item); 
   
    if (index < 0 || index > this->list_size) 
        throw std::out_of_range("Out of range exception.");

    else if (this->head == nullptr && index == 0) {
        this->head = new_last_node;
        this->tail = new_last_node;
    } else if (index == 0) {
        new_last_node->next = this->head;
        this->head = new_last_node;
    } else if (this->list_size == 1) {
        this->tail = new_last_node;
        this->tail->next = nullptr;
    } else if (this->list_size == index) {
        this->tail->next = new_last_node;
        this->tail = new_last_node;
    }
    else {
        Node<T>* tmp_head_p = this->head;

        for (int tmp_index = 0; tmp_index < index - 1; tmp_index++) {
            tmp_head_p = tmp_head_p->next;
        }
        new_last_node->next = tmp_head_p->next;
        tmp_head_p->next = new_last_node;
    }

    this->list_size++; 

    return;
}

template <typename T>
void LinkedList<T>::insert_first(T item) {
    this->insert(0, item);
    return;
}

template <typename T>
void LinkedList<T>::insert_last(T item) {
    this->add(item);
    return;
}

template <typename T> 
void LinkedList<T>::remove(int index) {
    if (this->head == nullptr || index < 0 || index > this->list_size - 1) 
        throw std::out_of_range("List out of range.");
    
    else if (this->list_size == 1) {
        delete this->head; 
        this->head = nullptr;
        this->tail = nullptr;
    }   

    else if (index == 0) { 
        Node<T>* obsolete_node = this->head;
        head = head->next; 
        delete obsolete_node;
    }  

    else if (index == this->list_size - 1) {
        Node<T>* tmp_head_p = this->head;
        
        while (tmp_head_p->next != this->tail) {
            tmp_head_p = tmp_head_p->next;
        }

        delete this->tail;
        this->tail = tmp_head_p;
        this->tail->next = nullptr;
    }
    else {
        Node<T>* tmp_head_p = this->head;
        
        for (int i = 0; i < index - 1; i++) {
            tmp_head_p = tmp_head_p->next;
        }

        Node<T>* obsolete_node = tmp_head_p->next;
        tmp_head_p->next = obsolete_node->next;
        delete obsolete_node;
    }

    this->list_size--; 

    return;
}

template <typename T>
void LinkedList<T>::clear() {
    while (this->head != nullptr) {
        Node<T>* obsolete_node = this->head;
        this->head = this->head->next;
        delete obsolete_node;
    }
    
    this->tail = nullptr;
    this->list_size = 0;

    return;
}

template <typename T>
void LinkedList<T>::remove_first() {
    this->remove(0);
    return;
}

template <typename T>
void LinkedList<T>::remove_last() {
    this->remove(this->list_size - 1);
    return;
}

template <typename T>
T LinkedList<T>::pop() {
    if (this->list_size == 0) 
        throw std::out_of_range("Cannot pop from an empty list.");
    
    T data = this->tail->data;
    this->remove(this->list_size - 1);
    return data;
}

template <typename T> 
int LinkedList<T>::size() { return this->list_size; }

template <typename T>
int LinkedList<T>::index_of(T item) {
    if (this->head == nullptr) throw std::range_error("Impossible to get index in empty list.");
    else if (this->list_size == 1) return 0;

    Node<T>* tmp_head_p = this->head;
    int index = 0;

    while (tmp_head_p->data != item) {
        tmp_head_p = tmp_head_p->next;
        index++;
    } 

    return index;
} 

template <typename T>
T LinkedList<T>::peek() {
    if (this->head == nullptr)
        throw std::out_of_range("Out of range exception.");
    return tail->data;
}

template <typename T>
bool LinkedList<T>::is_empty() { 
    return this->head == nullptr ? true : false; 
}

template <typename T>
std::string LinkedList<T>::to_string() {
    if (this->list_size == 0) 
        throw std::range_error("Impossible to parse empty list to string.");

    Node<T>* tmp = this->head;
    std::stringstream ss;

    while (tmp != nullptr) {
        ss << tmp->data << " ";
        tmp = tmp->next;
    }

    return ss.str();
}


#endif