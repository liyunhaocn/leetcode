#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int len = s.size();
        for(int i=0;i<len;i++){
            if(s[i]== 'M'){
                sum += 1000;
            }else if(s[i]== 'D'){
                sum += 500;
            } else if(s[i]== 'C'){
                if(s[i+1]== 'M'){
                    sum += 900;
                    i++;
                }else if(s[i+1]== 'D'){
                    sum += 400;
                    i++;
                }else{
                    sum += 100;
                }
            } else if(s[i]== 'L'){
                sum += 50;
            } else if(s[i]== 'X'){
                 if(s[i+1]== 'C'){
                    sum += 90;
                    i++;
                } else if(s[i+1]== 'L'){
                    sum += 40;
                    i++;
                } else{
                    sum += 10;
                }

            } else if(s[i]== 'V'){
                sum += 5;
            } else if(s[i]== 'I'){
                if(s[i+1]== 'X'){
                    sum += 9;
                    i++;
                } else if(s[i+1]== 'V'){
                    sum += 4;
                    i++;
                }else {
                    sum += 1;
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution Solution1;
    Solution1.romanToInt("MCMXCIV");
    return 0;
}
