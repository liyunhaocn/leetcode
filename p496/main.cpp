#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;
//map 记录每个nums2的位置
/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for( int i=0;i<nums2.size();i++){
            mp[ nums2[i] ] = i;
        }
        vector<int> ret;
        for( int i=0;i<nums1.size();i++){
            int pos = mp[ nums1[i] ];
            bool is = false;
            for( int j = pos+1;j < nums2.size();j ++ ){
                if( nums2[j] > nums1[i] ){
                    ret.push_back( nums2[j] );
                    is = true;
                    break;
                }
            }
            if(!is){
               ret.push_back( -1 );
            }

        }
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> mp;
        for( int i = 0;i < nums2.size();i ++){
            if( st.empty() ){
                st.push( nums2[i] );
            }else{
                int stop = st.top();
                if( nums2[i] < stop ){
                    st.push( nums2[i] );
                }else if(nums2[i] > stop){
                    while( !st.empty() && st.top() < nums2[i] ){
                        mp[ st.top()] = nums2[i];
                        st.pop();
                    }
                    st.push( nums2[i] );
                }
            }
        }
        while( !st.empty() ){
            mp[ st.top()] = -1;
            st.pop();
        }
        vector<int> ret;
        for( auto i: nums1 ){
            if( mp[i]!=0 ){
                ret.push_back( mp[i] );
            }else{
                ret.push_back( -1 );
            }

        }
        return ret;
    }
};
int main()
{
    Solution Solution1;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ret = Solution1.nextGreaterElement(nums1,nums2);
    for( auto i:ret ){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
