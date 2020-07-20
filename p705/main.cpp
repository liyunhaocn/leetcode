#include <iostream>
#include <string.h>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    bool * hx;
    MyHashSet() {
        hx = new bool [1000001];
        memset( hx,0,1000001 );
    }

    void add(int key) {
        hx[key] = true;
    }

    void remove(int key) {
        hx[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hx[key];
    }
};


int main()
{
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    hashSet.contains(1);// ���� true
    hashSet.contains(3);// ���� false (δ�ҵ�)
    hashSet.add(2);
    hashSet.contains(2);// ���� true
    hashSet.remove(2);
    hashSet.contains(2);//����false(�Ѿ���ɾ��)
    return 0;
}
