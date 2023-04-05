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
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+2,0);
        dp[n] = 0;
        for(int i = n-1; i>=0; i--){
            dp[i] = max(dp[i+1], dp[i+2] + nums[i]);
        }
    return dp[0];
    }
}; // 迭代




// class Solution {
// public:
//     vector<int> memo;
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         memo = vector<int>(n,-1);
//         return dp(nums, 0);
//     }
//     int dp(vector<int>& nums, int i){
//         int n = nums.size();
//         if(i >= n) return 0;
//         if(memo[i] != -1) return memo[i];
//         int res = INT_MIN;
//         res = max(dp(nums,i+2)+nums[i], dp(nums, i+1));
//         memo[i] = res;
//         return memo[i];
//     }
// };递归