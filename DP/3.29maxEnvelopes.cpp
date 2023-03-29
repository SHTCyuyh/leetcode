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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b){
            if(a[0] == b[0]) return a[1]>b[1];
            else{
               return a[0]< b[0];
            }
        });
        vector<int> height(n);
        for (int i =0;i<n; i++){
            height[i] = envelopes[i][1];
        }
        return lengthOfLIS(height);
    }
    int lengthOfLIS(vector<int>& nums){
        int piles = 0;
        vector<int> top(nums.size());
        for(int i: nums){
            int left = 0, right = piles;
            while(left < right){
                int mid = left + (right-left)/2;
                if(top[mid] == i) right = mid;
                if(top[mid] < i) left = mid+1;
                if(top[mid] > i) right = mid;
            }
            if(left == piles) piles++;
            top[left] = i;
        }
        return piles;
    }
};