// Classes and Objects
// Complete the class with all function definitions for a circular queue
// class Queue {
// int *data;
// int front, rear;
// public :
// Queue(int ); //create queue with specified size
// void add(int); //add specified element to the queue
// int remove();//delete element from the queue
// void disp(); //displays all elements in the queue(front to rear order)
// }
// Now, create a queue with size 10 add 2, 3, 4 and 5 in that order and finally delete two elements. Display
// elements present in the stack.



#include <iostream>

using namespace std;

class QueueOverFlow {};
class QueueUnderFlow {};

class Queue {
    int* data;
    int front;
    int rear;
    int capacity;   // total capacity of the queue
    int size;       // size of the queue at an instant

   public:
    Queue(int capacity) {
        this->capacity = capacity;
        data = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    void add(int data) {
        if (size == capacity) throw QueueOverFlow();
        if (size == 0) {
            front = 0;
            rear = -1;
        }
        rear = (rear + 1) % capacity;
        this->data[rear] = data;
        size++;
    }

    int remove() {
        if (size == 0) throw QueueUnderFlow();
        int toRet = data[rear--];
        if (rear == -1) rear = capacity - 1;
        size--;
        return toRet;
    }

    void disp() {
        for (int i = front, j = 0; j < size; i = (i + 1) % capacity, j++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(10);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    cout << "Removed : " << q.remove() << endl;
    cout << "Removed : " << q.remove() << endl;
    q.disp();
}
