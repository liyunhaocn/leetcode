#include <iostream>

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int * hx;
    MyHashMap() {
        hx = new int [1000001];
        memset( hx,-1,4*1000001 );
    }

    void put(int key,int val) {
        hx[key] = val;
    }

    void remove(int key) {
        hx[key] = -1;
    }

    /** Returns true if this set contains the specified element */
    int get(int key) {
        return hx[key];
    }
};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
