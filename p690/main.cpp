#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define debug(x) cout<<#x<<": "<<endl;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:

    map<int,int> emind;
    vector<Employee*> ems;
    int getImportance(vector<Employee*> employees, int id) {
        ems = employees;
        for(int i=0;i<employees.size();i++ ){
            emind[employees[i]->id] = i;
        }
        return findw( id );
    }
    int findw( int id ){
        int index = emind[id];
        if(  ems[ index ]->subordinates.size()==0 ){
            return ems[ index ]->importance;
        }else{
            int ret = 0;
            ret += ems[ index ]->importance;
            for( int idd : ems[ index ]->subordinates  ){
                ret += findw( idd );
            }
            return ret;
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.getImportance() << endl;
    return 0;
}
