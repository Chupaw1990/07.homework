#include <gtest/gtest.h>
#include <string>
#include "list_container.h"

template <typename T>
std::string container_string(list_container<T> &lst) {
    std::string str = "";
    for (size_t i = 0; i < lst.size(); i++) {
        str += std::to_string(lst[i]->data) + ' ';
    }
    return str;
}

TEST(ListTest, array_container) {
    list_container<int> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_back(i);
    }

    std::string values = container_string(lst);
    EXPECT_EQ(values, "0 1 2 3 4 5 6 7 8 9 ");
}

TEST(ListTest, array_pushback) {
    list_container<int> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    lst.push_back(42);
    std::string values = container_string(lst);
    EXPECT_EQ(values, "0 1 2 3 4 5 6 7 8 9 42 ");

    lst.push_back(718);
    std::string values_t = container_string(lst);
    EXPECT_EQ(values_t, "0 1 2 3 4 5 6 7 8 9 42 718 ");
}

TEST(ListTest, array_erase) {
    list_container<int> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    lst.erase(1);
    std::string values = container_string(lst);
    EXPECT_EQ(values, "0 2 3 4 5 6 7 8 9 ");

    lst.erase(8);
    std::string values_t = container_string(lst);
    EXPECT_EQ(values_t, "0 2 3 4 5 6 7 8 ");
}

TEST(ListTest, array_insert) {
    list_container<int> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    lst.insert(3, 42);
    std::string values = container_string(lst);
    EXPECT_EQ(values, "0 1 2 42 3 4 5 6 7 8 9 ");

    lst.insert(0, 718);
    std::string values_t = container_string(lst);
    EXPECT_EQ(values_t, "718 0 1 2 42 3 4 5 6 7 8 9 ");
}

TEST(ListTest, array_size) {
    list_container<int> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    EXPECT_EQ(lst.size(), 10);

    lst.erase(2);
    EXPECT_EQ(lst.size(), 9);

    lst.erase(0);
    EXPECT_EQ(lst.size(), 8);

    lst.push_back(42);
    EXPECT_EQ(lst.size(), 9);

    lst.insert(1, 718);
    EXPECT_EQ(lst.size(), 10);
}
