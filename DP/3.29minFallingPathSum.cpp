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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        if(n == 1) return matrix[0][0];
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                // cout<<j<<endl;
                if(j == 0) {
                    int add_trace = min(dp[i-1][j], dp[i-1][j+1]);
                    dp[i][j] = matrix[i][j] + add_trace;}
                if(j == n-1) {
                    int add_trace = min(dp[i-1][j], dp[i-1][j-1]);
                    dp[i][j] = matrix[i][j] + add_trace;}
                if(j>0 && j<n-1){
                    int add_trace = min(dp[i-1][j-1], (dp[i-1][j]<dp[i-1][j+1])?dp[i-1][j]:dp[i-1][j+1]);
                    dp[i][j] = matrix[i][j] + add_trace;}
                cout<< i<< j<<" "<<dp[i][j]<<endl;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<n; i++){
            res = min(res, dp[n-1][i]);
        }
        return res;
        //dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])

    }
};