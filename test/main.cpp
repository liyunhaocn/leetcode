#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    std::vector<int> demo{1,2};


    demo.insert(demo.end()-1, 3);
    demo.insert(demo.rebegin(), 3);

    for(int a:demo){
        cout<<a<<" ";
    }
    cout<<endl;

    demo.insert(demo.begin(), 4);

    for(int a:demo){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}
