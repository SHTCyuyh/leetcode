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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        int res = INT_MIN;
        for(int a:dp){
            res = max(res, a);
        }
        return res;
    }
};//DP


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0, right = 0;
        int windowsum = 0, maxsum = INT_MIN;
        while(right < nums.size()){
            windowsum += nums[right];
            right++;
            maxsum = max(windowsum, maxsum); 
            while(windowsum < 0){
                windowsum -= nums[left];
                left++;
            }

        }
        return maxsum;
    }
};//滑动窗口

