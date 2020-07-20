#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if( num1.size()==0 ){
            return num2;
        }else if( num2.size()==0 ){
            return num1;
        }else if( num1.size() < num2.size()){
            swap( num1,num2 );
        }
        int jin = 0;
        int i1 = num1.size()-1;
        int i2 = num2.size()-1;
        while( i1>=0 && i2>=0 ){
            num1[ i1 ] += num2[i2] - '0' + jin;
            if( num1[i1]>'9' ){
                num1[i1] -= 10;
                jin = 1;
            }else{
                jin = 0;
            }
            i1--;
            i2--;
        }
        while( jin==1 && i1 >= 0 ){
            num1[i1]+=1;
            if( num1[i1]>'9' ){
                num1[i1] -= 10;
                jin = 1;
            }else{
                jin = 0;
            }
            i1--;
        }
        if( jin==1 ){
            num1.insert(num1.begin(),'1');
        }
        return num1;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.addStrings("9998","2") << endl;
    return 0;
}
