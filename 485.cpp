#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    // int findMaxConsecutiveOnes(vector<int>& nums) {
    //     int MaxC =0, count =0;
    //     int n = nums.size();
    //     for(int i = 0;i<n;i++){
    //         if(nums[i] == 1 ){
    //             count ++;
    //         }else{
    //             MaxC = max(MaxC,count);
    //             count = 0;
    //         }
    //     }
    //         MaxC = max(MaxC,count);
    //         return MaxC;

    // }
    //双指针
    int findMaxConsecutiveOnes(vector<int>& nums){
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n && nums[j] == 1) j++;
            res = max(res,j- i);
            //j-i为当前1的个数
            i = j;
        }
        return res;
    }
    int max(int i, int j){
        return i>=j?i:j;
    }
};
int main(){
    vector<int> nums;
    int num;
    int i = 0;
    // while(i<5){
    //     scanf("%d",&num);
    //     nums[i] = num;
    //     i++;
    // }
    while((scanf("%d",&num)) != EOF){
        nums.push_back(num);
    }
    Solution solution;
    int result = solution.findMaxConsecutiveOnes(nums);
    printf("%d\n",result);
    return 0;

    
}