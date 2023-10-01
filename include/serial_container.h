#pragma once
#include <stdlib.h>

template <class T>
class serial_container {
   private:
    size_t _capacity = 0;
    T* _arr = new T;
    size_t _size = 0;

   public:
    class iterator {
        T* cur;

       public:
        iterator(T* first) : cur(first) {}

        T& operator+(int n) { return *(cur + n); }
        T& operator-(int n) { return *(cur + n); }

        T& operator++(int) { return *cur++; }
        T& operator--(int) { return *cur--; }
        T& operator++() { return *++cur; }
        T& operator--() { return *--cur; }

        bool operator!=(const iterator& it) { return cur != it.cur; }
        bool operator==(const iterator& it) { return cur == it.cur; }

        T& operator*() { return *cur; }
    };

    iterator begin() { return _arr; }
    iterator end() { return _arr + _size; }

    void push_back(const T& value) {
        if (_size == _capacity) {
            resize();
            _arr[_size] = value;
            _size++;
        } else {
            _arr[_size] = value;
            _size++;
        }
    }

    void insert(const unsigned int& pos, const T& value) {
        if (_size == _capacity) {
            resize();
        }
        for (size_t i = _size + 1; i > pos; --i) {
            _arr[i] = _arr[i - 1];
        }

        _arr[pos] = value;
        _size++;
    }

    void erase(const unsigned int& pos) {
        if (pos > _capacity || pos > _size) {
            throw std::invalid_argument("Erase position bigger than size container");
            return;
        }

        if (pos == _size) {
            _size--;
            return;
        }

        for (size_t i = pos + 1; i < _size; ++i) {
            _arr[i - 1] = _arr[i];
        }

        _size--;
    }

    size_t size() {
        return _size;
    }

    void resize() {
        if (_capacity == 0) {
            _capacity = 2;
        } else {
            _capacity *= 2;
        }

        T* new_region = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_region[i] = _arr[i];
        }
        delete[] _arr;
        _arr = new_region;
    }

    T operator[](size_t pos) {
        return T(_arr[pos]);
    }

    ~serial_container() {
        delete[] _arr;
    }
};