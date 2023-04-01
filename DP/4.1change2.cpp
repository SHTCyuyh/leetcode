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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n; i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1] <0) dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};//需要注意边界情况，dp[i]和coins[i-1]才对应！