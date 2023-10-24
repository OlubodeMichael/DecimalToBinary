//
//  DecimalToBinary.hpp
//  DecimalToBinary
//
//  Created by Michael Olubode on 10/20/23.
//

#ifndef DecimalToBinary_hpp
#define DecimalToBinary_hpp

#include <stdio.h>

class Stack {
private:
    struct StackNode{
        int value;
        struct StackNode* next;
    };
    
    StackNode *top;
public:
    Stack();
    ~Stack();
    void push(int value);  // Add an element to the top of the stack.
    void pop();  // Remove and return the element from the top of the stack.
    int Top();  // Return the element from the top of the stack without removing it.
    bool isEmpty();  // Check if the stack is empty.
    int size();
    void displayStack() const;
    
};



class Queue{
private:
    struct QueueNode{
        int value;
        struct QueueNode* next;
    };
    QueueNode* front;
    QueueNode* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    } 
    ~Queue();          // Destructor
    void enqueue(int value);  // Add an element to the rear of the queue
    void dequeue();     // Remove and return the element from the front of the queue
    bool isEmpty();
    void displayQueue() const;
};

#endif /* DecimalToBinary_hpp */
