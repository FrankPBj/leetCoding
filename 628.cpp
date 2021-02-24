#include<stdio.h>
#include<vector>
using namespace std;
class Solution{
    public:
    //线性扫描解法 最大值可能为最大的三个数相乘 也可能为最小的三个数相乘（存在负数情况）
        int maximumProduct(vector<int>& nums) {
            int min1= INT_MAX,min2 = INT_MAX;
            int max1 = INT_MIN,max2 = INT_MIN,max3= INT_MIN;
            for(int num:nums){
                if (num<min1){
                    min2 = min1;
                    min1 = num;
                }else if(num<min2){
                    min2 = num;
                }

                if(num>max1){
                    max3 = max2;
                    max2 = max1;
                    max1 = num;
                }else if(num>max2){
                    max3 = max2;
                    max2 = num;
                }else if(num> max3){
                    max3 = num;
                }
            }
        return max(min1*min2*max1,max1*max2*max3);

        }
        int max(int a,int b){
            return a>=b?a:b;
        }

};