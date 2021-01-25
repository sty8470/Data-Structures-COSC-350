#include <iostream>
using namespace std;

//Defining IntQueue Class
class IntQueue {
public:
    //Initializing a constructor
    IntQueue(void) {
        _size = 0;
        _front_index = 1;
        _rear_index = 0;
    }
    //checking an array whether it is empty
    bool is_empty(void) const {
        return _size == 0;
    }
    //Enqueuing values to a circular array
    void enqueue(int item) {
        _rear_index = (_rear_index + 1) % 8;
        _storage[_rear_index] = item;
        ++_size;
    }
    //Dequeuing values from a circular array
    int dequeue(void) {
        int temp = _storage[_front_index];
        _front_index = (_front_index+1) % 8;
                --_size;
        return temp;    }

    //Peeking the value at the very front
    int peek(void) const {
        return _storage[_front_index];
    }

    //Checking the current size of the circular array
    unsigned int size(void) const {
        return _size;
    }

//declaring private variables
private:
    static const unsigned int CAPACITY = 100;
    unsigned int _size;
    int _storage[CAPACITY];
    int _front_index;
    int _rear_index;
};




int main() {
    IntQueue q;

    if (!q.is_empty()) {
        cerr << "A new queue should be empty." << endl;
    }
    if (q.size() != 0) {
        cerr << "A new queue should have size 0." << endl;
    }
    q.enqueue(1);
    if (q.is_empty()) {
        cerr << "A queue containing one item should not be empty." << endl;
    }
    if (q.size() != 1) {
        cerr << "A queue containing one item should have size 1." << endl;
    }

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    if (q.is_empty()) {
        cerr << "A queue containing five items should not be empty." << endl;
    }
    if (q.size() != 5) {
        cerr << "A queue containing one item should have size 5." << endl;
    }

    while (q.size() > 1) {

        if (q.size() % 2 == 1) {
            q.enqueue(q.dequeue() + q.dequeue());
        }
        else {
            q.enqueue(q.dequeue() * q.dequeue());
        };

    }
    cout << "The sum of values in the queue is " << q.dequeue() << endl;

    if (!q.is_empty()) {
        cerr << "An emptied-out queue should be empty." << endl;
    }
    if (q.size() != 0) {
        cerr << "An emptied-out queue should have size 0." << endl;
    }

    return 0;
}