/*
 * Full name: Hemi Shah
 * Student ID: 2443456
 * Chapman Email: heshah@chapman.edu
 * Course number and section: CPSC-350-03
 * Assignment or exercise number: PA3: Do You See What I See?
 */

// THIS CODE IS FROM OUR CLASS LECTURE

#ifndef T_STACK_H
#define T_STACK_H
#include <iostream> 

// creates a template class for a stack called TStack
template <typename T>
class TStack{
    public:
        TStack(int iSize);
        ~TStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};


template <typename T>
TStack<T>::TStack(int iSize){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
}
template <typename T>
TStack<T>::~TStack(){
    // deallocates the stackArr
    delete[] stackArr; 
}
template <typename T>
bool TStack<T>::isFull(){
    // checks to see if count is the same as the maxSize, if so then the stack is full
    return (count == maxSize); 
}
template <typename T>
bool TStack<T>::isEmpty(){
    // checks to see if the count is 0, if so then the stack is empty
    return (count == 0);
}
template <typename T>
int TStack<T>::size(){
    // returns the count which is the size
    return count;
}
template <typename T>
void TStack<T>::push(T c){
    // checks to see if the stack is full, if so then it creates a new array for the stack
    // and copies the data over to it
    if(isFull()){
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }

    // adds the new element to the top of the stack and increments the count
    stackArr[++top] = c;
    ++count;
}

template <typename T>
T TStack<T>::pop(){
    // decrements the count and returns the top element on the stack after removing it
    --count;
    return stackArr[top--];
}

template <typename T>
T TStack<T>::peek(){
    // returns the top element on the stack
    return stackArr[top];
}
#endif