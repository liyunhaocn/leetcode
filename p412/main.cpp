#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


class Solution {
public:
    string int_str( int s ){
        stringstream ss;
        ss<<s;
        return ss.str();
    }
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for(int i=1;i<=n;i++){
            if( i%3 == 0 && i%5 == 0 ){
                ret.push_back( "FizzBuzz" );
            }else if( i%5 == 0 ){
                ret.push_back( "Buzz" );
            }else if( i%3 == 0 ){
                ret.push_back( "Fizz" );
            }else{
                ret.push_back( int_str(i) );
            }
        }
        return ret;

    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
