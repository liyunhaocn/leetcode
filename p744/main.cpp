#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if( letters.size()==0 ){
            return ' ';
        }
        int qian = 1;
        int hou = 1;
        while( hou < letters.size()){
            if( letters[hou] != letters[hou-1]){
                letters[qian++] = letters[hou];
            }
            hou++;
        }

        int l = 0;
        int r = qian-1;
        int mid = (l+r)/2;
        while( l<=r ){
            mid = (l+r)/2;
            if( letters[mid] < target ){
                l = mid + 1;
            }else if( letters[mid] > target ){
                r = mid - 1;
            }else{
                break;
            }
        }
        //debug(l)
        //debug(r)
        if(l>r){
            if( l== qian ){
                return letters[0];
            }else{
                return letters[l];
            }
        }else if( mid == qian-1 ){
            return letters[0];
        }else{
            return letters[mid+1];
        }
        return 'a';
    }
};

int main()
{
    Solution Solution1;
    vector<char> letters = {'c','c','c','c','f','j'};

    char target = 'c';

    cout << Solution1.nextGreatestLetter(letters,target) << endl;
    return 0;
}
