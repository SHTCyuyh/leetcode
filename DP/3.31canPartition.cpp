#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
#include<iostream>
#include<queue>
#include<stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums) sum += num;
        if(sum % 2 != 0) return false;
        int n = nums.size();
        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i=0;i<=n; i++) dp[i][0] = true;
        for(int i=1; i<=n;i++){
            for(int j=1; j<=sum; j++){
                if(j-nums[i] < 0) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
    }
};