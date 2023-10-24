//
//  main.cpp
//  DecimalToBinary
//
//  Created by Michael Olubode on 10/20/23.
//

#include <iostream>
#include "DecimalToBinary.hpp"
using namespace std;

void convertAndPush(Stack &, int);
void convertAndEnqueue(Queue &, double, int);
int main() {
    Stack s;
    Queue q;
    
    double decimal;
    int places;
    do {
        cout << "Enter the decimal you want to convert: \n";
        cin >> decimal;
    } while(decimal < 0);
    do {
        cout << "How many places do you want for the decimal: \n";
        cin >> places;
    }while(places < 0);
    
    int num = static_cast<int>(decimal);
    double decNum = decimal - num;
    
    convertAndPush(s, num);
    convertAndEnqueue(q, decNum, places);
    
    cout << "Binary representation of the integer part: ";
    s.displayStack();

    cout << "Binary representation of the fractional part: ";
    q.displayQueue();
    
    return 0;
}

void convertAndPush(Stack &s, int num) {
    if (num == 0) {
        return;
    } else {
        int remainder = num % 2;
        s.push(remainder);
        convertAndPush(s, num / 2);
    }
}

void convertAndEnqueue(Queue &q, double decimal, int precision) {
    if(precision == 0) {
        return;
    } else {
        decimal *= 2;
        int bit = static_cast<int>(decimal);
        q.enqueue(bit);
        decimal -= bit;
        convertAndEnqueue(q, decimal, precision - 1);
    }
}
