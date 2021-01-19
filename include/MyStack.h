// Copyright 19.01.21 DenisKabanov

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>
#include <string>

template<typename T>
class MyStack {
 private:
    int sizeofstack;
    int last;
    T* content;

 public:
    explicit MyStack(int sizeofstack) {
        if (sizeofstack != 0) {
            this->sizeofstack = sizeofstack;
            this->last = 0;
            this->content = new T[this->sizeofstack];
        }
    }

    MyStack(const MyStack& prevstack) {
        this->sizeofstack = prevstack.sizeofstack;
        this->last = prevstack.last;
        this->content = new T[this->sizeofstack];
        for (int i = 0; i < this->sizeofstack; i++) {
            this->content[i] = prevstack.content[i];
        }
    }

    ~MyStack() {
        this->sizeofstack = 0;
        this->last = 0;
        delete[] content;
    }

    T get() const {
        if (this->last != 0) {
            return this->content[last - 1];
        }
    }

    T pop() {
        if (isEmpty()) {
            std::cout << std::endl << "Stack is empty";
        } else {
            this->last--;
            return this->content[this->last];
        }
    }

    void push(T newlast) {
        if (isFull()) {
            std::cout << std::endl << "Stack is full";
        } else {
            this->content[last] = newlast;
            this->last++;
        }
    }

    bool isFull() const {
        if (this->last == this->sizeofstack)
            return true;
        else
            return false;
    }

    bool isEmpty() const {
        if (this->last == 0) {
            return true;
        } else {
            return false;
        }
    }
};

#endif  // INCLUDE_MYSTACK_H_
