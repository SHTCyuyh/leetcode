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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        memo = vector(m, vector<int>(n,-1));
        return dp(grid,m-1,n-1);
    }
    vector<vector<int>> memo;
    int dp(vector<vector<int>>& grid, int i, int j){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = min(dp(grid,i-1,j), dp(grid, i, j-1)) + grid[i][j];
        return memo[i][j];


    }
};//递归


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int j=1;j<n;j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for(int i=1; i<m; i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) +grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
}; // 迭代
