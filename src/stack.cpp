#include "../include/stack.h"
#include <iostream>

// constructor 
Stack::Stack(int size)
{
    size_ = size;
    top_ = -1;
    data_ = new char[size_];
}

// destructor
Stack::~Stack()
{
    delete[] data_;
}

// push element
void Stack::Push(char ch)
{
    if(!Stack::Full())
    {
        top_++;
        data_[top_] = ch;
    }else
    {
        std::cout << "stack is full" << std::endl;
    }
}

// pop element
char Stack::Pop()
{
    char ret;
    if(!Stack::Empty())
    {
        ret = data_[top_];
        top_--;
    }else
    {
        std::cout << "stack is empty" << std::endl;
        ret = -1;
    }
    return ret;
}

// get top of stack element
char Stack::Top()
{
    return data_[top_];
}

// stack is empty
bool Stack::Empty()
{
    if(top_ == -1)
    {
        return true;
    }else
    {
        return false;
    }
}

// stack is full
bool Stack::Full()
{
    if(top_ == size_)
    {
        return true;
    }else
    {
        return false;
    }
}

// set stack empty
void Stack::SetNull()
{
    top_ = -1;
}

// print stack element
void Stack::StackPrint()
{

    if(!Stack::Empty())
    {
        while(top_ != -1)
        {
            std::cout << Stack::Pop() << std::endl;
        }
    }else
    {
        std::cout << "stack is empty\n";
    }
}
