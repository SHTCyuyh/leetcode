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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int res = 0;
        for(int i =0;i<dp.size(); i++){
            res = max(res, dp[i]);
        }
    return res;
    }
}; // 暴力


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int piles = 0;
        vector<int> top(nums.size());
        for(int i=0; i<nums.size(); i++){
            int e = nums[i];
            int left = 0, right=piles-1;
            while(left < right){
                int mid = left + (right - left)/2 ;
                if(nums[mid] < e) left = mid+1;
                if(nums[mid] > e) right = mid;
                if(nums[mid] == e) right = mid;
            }
            if(left == piles) piles++;
            top[left] = e;
        }
        return piles;
    }
}; // 二分查找

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int piles = 0;    // 牌堆数初始化为 0
    vector<int> top(nums.size());   // 牌堆数组 top
    for (int i = 0; i < nums.size(); i++) {
        int poker = nums[i];    // 要处理的扑克牌
        int left = 0, right = piles;    // 搜索区间为 [left, right)
        while (left < right) {
            int mid = (left + right) / 2;    // 防溢出
            if (top[mid] > poker) {
                right = mid;
            } else if (top[mid] < poker) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == piles) piles++;
        top[left] = poker;
    }
    return piles;
    }
};