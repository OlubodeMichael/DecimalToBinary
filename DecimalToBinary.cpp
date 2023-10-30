//
//  DecimalToBinary.cpp
//  DecimalToBinary
//
//  Created by Michael Olubode on 10/20/23.
//

#include "DecimalToBinary.hpp"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    StackNode* newNode = new StackNode;
    newNode->value = value;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (!isEmpty()) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}


bool Stack::isEmpty() {
    return top == nullptr;
}
int Stack::Top() {
    return top->value;
}

int Stack::size() {
    int count = 0;
    StackNode* current = top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void Stack::displayStack() const {
    StackNode* current;
    current = top;
    
    while (current != nullptr) {
        cout << current->value << " ";;
        current = current->next;
    }
    cout << endl;
}




// Queue
Queue::~Queue() {
    while(front) {
        QueueNode *nodePtr = front;
        front = front->next;
        delete nodePtr;
    }
}

void Queue::enqueue(int value) {
    QueueNode *newNode;
    newNode = new QueueNode;
    newNode->value = value;
    newNode->next = nullptr;
    
    if(!front) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}


void Queue::dequeue() {
    QueueNode *newNode = front;
    front = front->next;
    delete newNode;
}

bool Queue::isEmpty() {
    if(!front) {
        return true;
    } else {
        return false;
    }
}

void Queue::displayQueue() const {
    QueueNode* current = front;
    while (current != nullptr) {
    cout << current->value << " ";
    current = current->next;
    }
    cout << endl;
}
