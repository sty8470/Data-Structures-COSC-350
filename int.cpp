#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

#include "intlist.h"

ostream &operator<<(ostream &os, const IntList &int_list);

int main (int argc, char * const argv[]) {

    // Retrieve the array values from the command line.
    // Check that at least three command-line arguments are provided,
    // the program name, the value to search for, and array values
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << "<int> [<int>]..." << endl;
        cerr << "Enter list values as command line arguments." << endl;
        return 1;
    }

    IntList int_list;

    // Convert each command-line values to an int value and store it in array a
    int n = argc - 1;
    int a[n];  // Declare an array of n int values
    for (int k = 1 ; k < argc ; ++k) {
        a[k-1] = atoi(argv[k]);
    }

    // Cause stdout to be flushed after every << operation
    // http://stackoverflow.com/questions/6214629/stdout-and-need-to-flush-it-c
    std::cout.setf( std::ios_base::unitbuf );

    // Check append(), get_item_at(), and size()
    cout << "Check append(), operator[](), and size()" << endl;
    for (int k = 0; k < n; ++k) {
        assert(int_list.size() == k);
        cout << "After appending " << a[k] << ": " << flush;
        int_list.append(a[k]);
        cout << int_list << endl;
        assert(int_list.size() == k+1);
        for (int j = 0; j < int_list.size(); ++j) {
            assert(int_list.get_item_at(j) == a[j]);
        }
    }
    cout << endl;

    // Check pop(), get_item_at, and size() by popping half of the values randomly
    cout << "Check pop(), at, and size() by popping half of the values randomly" << endl;
    int popped_value;
    for (int k = n; k > n / 2; --k) {
        // Generate a random index
        int j = rand() % k;

        assert(int_list.get_item_at(j) == a[j]);
        cout << "After pop from index " << j << ": " << flush;
        popped_value = int_list.pop(j);
        cout << int_list << '(' << popped_value << " was popped)" << endl;
        assert(int_list.size() == k-1);
        copy(a+(j+1), a+k, a+j);
    }
    cout << endl;

    cout << "After inserting the value 200 at index " << int_list.size() << ": " << flush;
    int_list.insert(int_list.size(), 200);
    cout << int_list << endl;
    assert(int_list.get_item_at(int_list.size() -  1) == 200);

    cout << "After inserting the value 300 at index 0: " << flush;
    int_list.insert(0, 300);
    cout << int_list << endl;
    assert(int_list.get_item_at(0) == 300);

    int m = int_list.size() / 2;
    cout << "After inserting the value 400 at index " << m << ": " << flush;
    int_list.insert(m, 400);
    cout << int_list << endl;
    assert(int_list.get_item_at(m) == 400);

    cout << endl;

    cout << "Check set_item_at()" << endl;
    for (int i = 0; i < int_list.size(); ++i) {
        int item = int_list.get_item_at(i);
        cout << "set_item_at(" << i << ", " << item + 1 << ')' << endl;
        int_list.set_item_at(i, item + 1);
        cout << "The list is now " << int_list << endl;
        assert(int_list.get_item_at(i) == item + 1);
    }

    return 0;
}

// A function that overloads the << operator for IntList objects
ostream &operator<<(ostream &os, const IntList &int_list) {
    if (int_list.size() == 0) {
        os << "[]";
    }
    else {
        os << '[' << int_list.get_item_at(0);
        for (int i = 1; i < int_list.size(); ++i) {
            os << ", " << int_list.get_item_at(i);
        }
        os << ']';
    }
    return os;
}
