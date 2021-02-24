#include<stdio.h>
#include<vector>
using namespace std;

// 动态规划解法
// timeSerires[i] > timeSeries[i-1]+duration时 中毒时间正常累计
// timeSerires[i] <= timeSeries[i-1]+duration 时 中毒时间只能加timeSeries[i] - timeSeries[i-1]
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0){
            return 0;
        }
        int n = timeSeries.size();
        vector<int> dp;
        dp.push_back(duration);
        for(int i=1; i <n;i++){
            if(timeSeries[i] > timeSeries[i-1]+duration) dp.push_back(dp[i-1]+duration);
            else if(timeSeries[i]<=timeSeries[i-1]+duration) dp.push_back(timeSeries[i]-timeSeries[i-1]+dp[i-1]);
        }
        return dp.back();

    }
};