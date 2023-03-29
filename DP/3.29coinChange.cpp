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
    unordered_map<int, int> mp;
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount, mp);
    }
    int dp(vector<int>& coins, int amount, unordered_map<int,int> &mp){
        if(mp.count(amount)) return mp[amount];
        if (amount == 0) {
            mp[0] = 0;
            return 0;}
        if (amount < 0 ){
            return -1;
        }
        int res = INT_MAX;
        for(int coin:coins){
            int sub = dp(coins,amount-coin, mp);
            if(sub == -1) continue;
            res = min(res, sub+1);
        }
        mp[amount] = (res == INT_MAX)? -1:res;
        return mp[amount];
    }
};//自顶向下


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=0; i<dp.size(); i++){
            for(int coin: coins){
                if(i-coin<0) continue;
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return (dp[amount] == amount+1?-1:dp[amount]);
    }
};//自底向上


