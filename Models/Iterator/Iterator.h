//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_ITERATOR_H
#define TEST_ITERATOR_H


#include <iterator>

namespace DDP {
    template <typename T>
    class Iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T &;


        explicit Iterator(pointer ptr = nullptr) : ptr(ptr) {}
        Iterator(const Iterator & other) : ptr(other.ptr) {}


        bool operator==(const Iterator & other) { return ptr == other.ptr; }
        bool operator!=(const Iterator & other) { return ptr != other.ptr; }

        Iterator & operator+=(difference_type diff) { ptr += diff; return *this; }
        Iterator & operator-=(difference_type diff) { ptr -= diff; return *this; }

        Iterator & operator++() { ++ptr; return *this; }
        Iterator & operator--() { --ptr; return *this; }


//        Iterator operator++(int) { pointer copy = ptr; ++ptr; return copy; }
//        Iterator operator--(int) { pointer copy = ptr; --ptr; return copy; }

        Iterator operator+(difference_type diff) { Iterator copy = *this; copy += diff; return copy; }
        Iterator operator-(difference_type diff) { Iterator copy = *this; copy -= diff; return copy; }

        difference_type operator-(const Iterator & other) { return std::distance(other.ptr, ptr); }

        reference operator*() { return *ptr; }
        const_reference operator*() const { return *ptr; }
        pointer operator->()  { return ptr; }

    protected:
        pointer ptr;
    };
}

#endif //TEST_ITERATOR_H
