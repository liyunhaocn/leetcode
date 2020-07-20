#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> minute = {1,2,4,8,16,32};
    vector<int> hour = {1,2,4,8};
    vector<string> ret;
    vector<string> m;
    vector<string> h;
    vector<string> readBinaryWatch(int num) {

        for( int i=0;i<=num;i++ ){
            if( i<=4 ){
                m.clear();
                h.clear();
                findh(i,0,0);
                findm(num-i,0,0);
                for( auto i:h ){
                    for(auto j:m ){
                        ret.push_back(i+":"+j);
                    }
                }
            }
        }
        return ret;
    }
    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    void findh( int num,int pos,int cursum ){
        //debug(cursum)
        if(num < 0){
            return ;
        }if(num == 0){
            if( cursum>=12 ){
                return;
            }
            h.push_back( int_str(cursum ) );
        }else{
            if( pos<hour.size() ){
                findh( num-1, pos+1,cursum + hour[pos] );
                findh( num, pos+1,cursum );
            }
        }
    }
    void findm( int num,int pos,int cursum ){
        //debug(cursum)
        if(num < 0){
            return ;
        }if(num == 0){
            if( cursum>=60 ){
                return;
            }
            string temp = int_str(cursum );
            if( temp=="0" ){
                m.push_back( "00" );
            }else if(temp.size()==1){
                m.push_back( string(1,'0')+temp );
            }else{
                m.push_back(temp );
            }

        }else{
            if( pos<minute.size() ){
                findm( num-1, pos+1,cursum + minute[pos] );
                findm( num, pos+1,cursum );
            }
        }
    }

};

int main()
{
    Solution Solution1;
    vector<string> ret = Solution1.readBinaryWatch(0) ;

    for(auto i:ret){
        debug(i)
    }
    return 0;
}
