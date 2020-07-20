#include <iostream>
#include <queue>

using namespace std;



class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        ;
    }

    int ping(int t) {
        q.push(t);
        while ( !q.empty() && q.front() < t - 3000)
            q.pop();
        return q.size();
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}

