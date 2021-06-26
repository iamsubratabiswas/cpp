// Classes and Objects
// Complete the class with all function definitions for a stack
// class Stack {
// int *buffer, top;
// public :
// Stack(int); //create a stack with specified size
// void push(int); //push the specified item
// int pop(); //return the top element
// void disp(); //displays elements in the stack in top to bottom order}
// Now, create a stack with size 10, push 2, 3, 4 and 5 in that order and finally pop one element. Display elements
// present in the stack.


#include <iostream>

using namespace std;

class StackOverFlow{};
class StackUnderFlow{};

class Stack {
    int* buffer;
    int top;
    int size;
   public : 
    Stack(int size) {
        this->size = size;
        buffer = new int[size];
        top = -1;
    }
    
    void push(int data) {
        if (top == size - 1) throw StackOverFlow();
        buffer[++top] = data;
    }

    int pop() {    
        if (top == -1) throw StackUnderFlow();
        return buffer[top--];
    }

    void disp() {
        for (int i = top; i >= 0; i--) cout << buffer[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s(10);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Popped : " << s.pop() << endl;
    s.disp();
}
