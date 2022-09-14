#include "List.h"

#ifndef STACK

#define STACK 1

template <class T>
class Stack {
    private:
        List<T>* stackList;


    public:
        Stack() {
            stackList = new List<T>();
        }

        void push(T* pData) {
            stackList->insert(0, pData);
        }

        T* pop() {
            T* result = NULL;
            if (!stackList->isEmpty())
            {
                result = stackList->find(0);
                stackList->remove(0);
            }
            return result;
        }

        T* top() {
            T* result = NULL;
            if (!stackList->isEmpty())
            {
                result = stackList->find(0);
            }
            return result;
        }

        bool isEmpty() {
            return stackList->isEmpty();
        }
};


#endif