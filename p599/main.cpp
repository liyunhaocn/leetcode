#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> mp;
        vector<string> retv;
        int ret = list1.size()+list2.size();
        for(int i=0;i<list1.size();i++){
            mp[ list1[i] ] = i+1;
        }
        for(int i=0;i<list2.size();i++){
            if( mp[ list2[i] ] > 0 ) {
                if( ret > mp[ list2[i] ] + i+1  ){
                    retv.clear();
                    retv.push_back( list2[i] );
                    ret = mp[ list2[i] ] + i+1;
                }else if(ret == mp[ list2[i] ] + i+1){
                    retv.push_back( list2[i] );
                }
            }
        }
        return retv;
    }
};

int main()
{
    Solution Solution1;
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    for(auto i:Solution1.findRestaurant(list1,list2) ){
        cout<<i<<endl;
    }
    return 0;
}
