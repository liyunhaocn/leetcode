#include <iostream>
#include <vector>

using namespace std;

/*
class NumArray {
public:
    vector<int> sum;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        sum = vector<int>( nums.size()+1,0 );

        for(int i = 0;i < nums.size();i++){
            sum[i+1] = sum[i] + nums[i];
        }
    }

    void update(int i, int val) {
        nums[i] = val;
        for( int pos = i;pos < nums.size();pos++){
            sum[pos+1] = sum[pos] + nums[pos];
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};
*/

#define debug(x) cout<<#x<<": "<<x<<endl;

class NumArray {
public:

    vector<int> nums;

    struct node{
        int l;
        int r;
        int v;
        node(int l,int r,int v):l(l),r(r),v(v){}
        node():l(0),r(0),v(0){}
    };

    vector<node> nodes;

    bool build(int n,int l,int r){
        //debug( l )
        //debug( r )

        if( l>r ){
            return false;
        }
        int mid = (l+r)/2;
        nodes[n].l = l;
        nodes[n].r = r;
        if(l==r){
            nodes[n].v = nums[l];
            //debug( nums[l] )
            return true;
        }
        build( 2*n+1,l,mid );
        build( 2*n+2, mid+1,r);
        nodes[n].v = nodes[2*n+1].v + nodes[2*n+2].v;
        //debug(nodes[n].v)
        return true;
    }

    NumArray(vector<int>& nums) {
        if( nums.size()==0 ){
            return;
        }

        this->nums = nums;
        nodes = vector<node>(nums.size()*4);
        build(0,0,nums.size()-1);

        /*for(int i=0;i<nodes.size();i++){
            debug(nodes[i].l)
            debug(nodes[i].r)
            debug(nodes[i].v)
        }*/
    }

    void up(int n,int i,int val){

        int mid = (nodes[n].l + nodes[n].r)/2;

        if( nodes[n].l == nodes[n].r && nodes[n].r == i ){
            nodes[n].v = val;
        }else{
            if( i <= mid ){
                up(n*2+1,i,val);
            }else if( i>mid ){
                up(n*2+2,i,val);
            }
            nodes[n].v = nodes[n*2+1].v + nodes[n*2+2].v;
        }
    }

    void update(int i, int val) {
        if( i<0 || i>= nums.size()){
            return;
        }
        up(0,i,val);
    }

    int findSum(int n,int i,int j){

        int mid = (nodes[n].l + nodes[n].r)/2;
        if( j < nodes[n].l || i > nodes[n].r){
            return 0;
        }
        if( nodes[n].l == nodes[n].r ){
            return nodes[n].v;
        }else if( j <= mid ){
            return findSum( n*2+1, i,j);
        }else if( i > mid ){
            return findSum( n*2+2, i,j);
        }else{
            return findSum( n*2+1, i,mid) + findSum( n*2+2, mid+1,j);
        }
        return 0;
    }
    int sumRange(int i, int j) {

        if( j<0 || i>= nums.size()){
            return 0;
        }
        i = max( 0,i );
        int r = nums.size()-1;
        j = min( r,j );
        return findSum(0,i,j);
    }
};


int main()
{
    vector<int> ve = {2};
    NumArray Solution1(ve);

    cout<<Solution1.sumRange(0,0)<<endl ;

    Solution1.update(0,5);
    cout<<Solution1.sumRange(0,0)<<endl ;
    //Solution1.update(1,2);
    return 0;
}
