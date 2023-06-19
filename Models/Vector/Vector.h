//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H


#include "Iterator.h"

namespace DDP {
    template <typename T>
    class Vector {
    public:
        using iterator = Iterator<T>;
        using const_iterator = Iterator<const T>;

        explicit Vector(size_t = 0);
        Vector(std::initializer_list<T>);
        ~Vector();

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;

        void push_back(T);
        void pop_back();

        iterator erase(iterator);

        size_t size() const;

        T & operator[](int);
        const T & operator[](int) const;

    private:
        T * data_;
        size_t capacity_;
        size_t size_;
    };


    template <typename T>
    Vector<T>::Vector(size_t size) : data_(new T[size]), capacity_(size), size_(size) {}

    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> list) : data_(new T[list.size()]), capacity_(list.size()), size_(list.size()) {
        for (auto iter = list.begin(); iter != list.end(); ++iter)
            data_[iter - list.begin()] = *iter;
    }

    template <typename T>
    Vector<T>::~Vector() {
        delete[] data_;
    }


    template <typename T>
    Iterator<T> Vector<T>::begin() { return iterator(data_); }

    template <typename T>
    Iterator<T> Vector<T>::end() { return iterator(data_ + size_); }


    template <typename T>
    Iterator<const T> Vector<T>::cbegin() const { return iterator(data_); }

    template <typename T>
    Iterator<const T> Vector<T>::cend() const { return iterator(data_ + size_); }


    template <typename T>
    void Vector<T>::push_back(T element) {
        if (capacity_ == size_) {
            capacity_ = (size_ + 1) * 3 / 2;
            T * newData = new T[capacity_];
            memcpy(newData, data_, size_ * sizeof(T));
            delete[] data_;
            data_ = newData;
        }
        data_[size_] = element;
        ++size_;
    }

    template <typename T>
    void Vector<T>::pop_back() {
        if (size_ == 0)
            return;
        --size_;
    }


    template <typename T>
    Iterator<T> Vector<T>::erase(Iterator<T> iter) {
        if (iter == end())
            return end();
        size_t position = iter - begin();
        for (size_t i = position; i + 1 < size_; ++i)
            data_[i] = data_[i + 1];
        --size_;
        return begin() + position;
    }


    template <typename T>
    size_t Vector<T>::size() const { return size_; }


    template <typename T>
    T & Vector<T>::operator[](int i) { return data_[i]; }
    template <typename T>
    const T & Vector<T>::operator[](int i) const { return data_[i]; }
}

#endif //TEST_VECTOR_H
