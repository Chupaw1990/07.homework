#pragma once
#include <stdlib.h>

#include <memory>

template <typename T>
struct Node {
    Node<T> *prev;
    Node<T> *next;
    T data;

    Node(T data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

template <class T>
class list_container {
   public:
    list_container() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    Node<T> *push_back(T data) {
        Node<T> *ptr = new Node<T>(data);

        ptr->prev = tail;

        if (tail != nullptr)
            tail->next = ptr;
        if (head == nullptr)
            head = ptr;
        tail = ptr;

        _size++;

        return ptr;
    }

    Node<T> *push_front(T data) {
        Node<T> *ptr = new Node<T>(data);

        ptr->next = head;
        if (head != nullptr)
            head->prev = ptr;
        if (tail == nullptr)
            tail = ptr;
        head = ptr;

        _size++;

        return ptr;
    }

    void pop_front() {
        if (head == nullptr)
            return;

        Node<T> *ptr = head->next;
        if (ptr != nullptr)
            ptr->prev = nullptr;
        else
            tail = nullptr;

        delete head;

        head = ptr;
        _size--;
    }

    void pop_back() {
        if (tail == nullptr)
            return;

        Node<T> *ptr = tail->prev;
        if (ptr != nullptr)
            ptr->next = nullptr;
        else
            head = nullptr;

        delete tail;

        tail = ptr;

        _size--;
    }

    size_t size() { return _size; }

    Node<T> *get_at(size_t index) {
        if (index > _size) {
            throw std::invalid_argument("Invalid list index");
        }

        Node<T> *ptr = head;
        size_t n = 0;

        while (n != index) {
            if (ptr == nullptr)
                return ptr;
            ptr = ptr->next;
            n++;
        }

        return ptr;
    }

    Node<T> *operator[](int index) {
        return get_at(index);
    }

    Node<T> *insert(int index, T data) {
        Node<T> *right = get_at(index);
        if (right == nullptr)
            return push_back(data);

        Node<T> *left = right->prev;
        if (left == nullptr)
            return push_front(data);

        Node<T> *ptr = new Node<T>(data);

        ptr->prev = left;
        ptr->next = right;
        left->next = ptr;
        right->prev = ptr;

        _size++;

        return ptr;
    }

    void erase(int index) {
        Node<T> *ptr = get_at(index);
        if (ptr == nullptr)
            return;

        if (ptr->prev == nullptr) {
            pop_front();
            return;
        }

        if (ptr->next == nullptr) {
            pop_back();
            return;
        }

        Node<T> *left = ptr->prev;
        Node<T> *right = ptr->next;
        left->next = right;
        right->prev = left;

        _size--;

        delete ptr;
    }

    ~list_container() {
        while (head != nullptr)
            pop_front();
    }

   private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    size_t _size = 0;
};
