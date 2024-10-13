/*
 * Full name: Hemi Shah
 * Student ID: 2443456
 * Chapman Email: heshah@chapman.edu
 * Course number and section: CPSC-350-03
 * Assignment or exercise number: PA3: Do You See What I See?
 */

#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
#include "TStack.h"

// creates a MonoStack class using the TStack template to handle the logic to create a monostack
template<typename T>
class MonoStack : public TStack<T>{
    public:
    MonoStack(int initialSize, char o);
    ~MonoStack();

    // interface
    void push(T value); // add f to the top of stack
    float pop(); // remove the element sitting at the top of the stack
    float peek(); // return the element sitting at the top of the stack

    // helper methods
    bool isFull(); // tells us if the stack is full or not
    bool isEmpty(); // tells us if the stack is empty or not
    int size(); // tells us how many elements are actually in the stack

    private:
    char stackOrder; // order of the monostack (ascending/descending)
};

template<typename T>
MonoStack<T>::MonoStack(int initialSize, char order) : TStack<T>(initialSize), stackOrder(order) {
    // everything is intitialized inside the template class
}

template<typename T>
MonoStack<T>::~MonoStack(){
    // deletes stackArr in TStack
}

template<typename T>
bool MonoStack<T>::isFull(){
    // uses the TStack definition for isFull()
    return TStack<T>::isFull(); 
}

template<typename T>
bool MonoStack<T>::isEmpty(){
    // uses the TStack definition for isEmpty()
    return TStack<T>::isEmpty(); 
}

template<typename T>
int MonoStack<T>::size(){
     // uses the TStack definition for size()
    return TStack<T>::size();
}

template<typename T>
void MonoStack<T>::push(T f) {
    if (this->isFull()) {
        // creates a temporary stack with double the size
        MonoStack<T> temp(this->size() * 2, stackOrder);
        
        // moves all of the elements to temp stack
        while (!this->isEmpty()) {
            temp.TStack<T>::push(this->pop());
        }
        
        // moves all of the elements back to this stack
        while (!temp.isEmpty()) {
            this->TStack<T>::push(temp.pop());
        }
    }

    // for decreasing stack
    if (stackOrder == 'd') {
        while (!this->isEmpty() && this->peek() < f) {
            this->pop();
        }
    } 
    // for increasing stack
    else if (stackOrder == 'i') {
        while (!this->isEmpty() && this->peek() > f) {
            this->pop();
        }
    }

    // pushes f onto the stack
    this->TStack<T>::push(f); 
}

template<typename T>
float MonoStack<T>::pop() {
    // uses the TStack definition of pop and converts to float
    return static_cast<float>(TStack<T>::pop()); 
}

template<typename T>
float MonoStack<T>::peek(){
    // uses the TStack definition of peek and converts to float
    return static_cast<float>(TStack<T>::peek()); 
}

#endif