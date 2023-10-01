#include <iostream>

#include "list_container.h"
#include "serial_container.h"

int main() {
    serial_container<int> arr;
    list_container<int> lst;

    std::cout << "*Initialization*" << std::endl;
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
        lst.push_back(i);
    }

    std::cout << "Vector: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "List: ";
    for (size_t i = 0; i < lst.size(); i++) {
        std::cout << lst[i]->data << ' ';
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "****Size****" << std::endl;

    std::cout << "Vector size: " << arr.size() << std::endl;
    std::cout << "List size: " << lst.size() << std::endl;
    std::cout << std::endl;

    std::cout << "***Erase***" << std::endl;
    arr.erase(2);
    arr.erase(3);
    arr.erase(4);
    lst.erase(2);
    lst.erase(3);
    lst.erase(4);
    std::cout << "Vector: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "List: ";
    for (size_t i = 0; i < lst.size(); i++) {
        std::cout << lst[i]->data << ' ';
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "***Insert***" << std::endl;
    arr.insert(0, 10);
    lst.insert(0, 10);
    std::cout << "Vector: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "List: ";
    for (size_t i = 0; i < lst.size(); i++) {
        std::cout << lst[i]->data << ' ';
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "*Insert middle*" << std::endl;
    arr.insert(arr.size() / 2, 20);
    lst.insert(lst.size() / 2, 20);

    std::cout << "Vector: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "List: ";
    for (size_t i = 0; i < lst.size(); i++) {
        std::cout << lst[i]->data << ' ';
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "**Push back**" << std::endl;
    arr.push_back(30);
    lst.push_back(30);

    std::cout << "Vector: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "List: ";
    for (size_t i = 0; i < lst.size(); i++) {
        std::cout << lst[i]->data << ' ';
    }
    std::cout << std::endl
              << std::endl;

    return 0;
}