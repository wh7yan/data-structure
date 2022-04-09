#ifndef _STACK_
#define _STACK_

// char type
class Stack
{
    private:
        char *data_;  // linear list
        int size_;    
        int top_;   

    public:
        Stack(int size = 10);
        ~Stack();
        void Push(char ch);
        char Pop();
        char Top();
        bool Empty();
        bool Full();
        void SetNull();
        void StackPrint();

        class ExceptionEmpty{};
        class ExceptionFull{};

};

#endif