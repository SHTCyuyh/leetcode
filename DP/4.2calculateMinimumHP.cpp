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



// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//             int m = dungeon.size();
//             int n = dungeon[0].size();
//             memo = vector(m, vector<int>(n, -1));
//             return dp(dungeon,0,0);
//     }
//     vector<vector<int>> memo;
//     int dp(vector<vector<int>>& grid, int i, int j){
//             int m = grid.size();
//             int n = grid[0].size();    
//             if(i==m-1 && j == n-1){
//                 return grid[i][j] >=0 ? 1:-grid[i][j] +1;
//             }   
//             if(i == m || j == n) return INT_MAX;
//             if(memo[i][j] != -1) return memo[i][j];
//             int res = min(dp(grid, i, j+1),
//                           dp(grid, i+1, j)
//                             ) - grid[i][j];
//             memo[i][j] = res <= 0? 1:res;
//             return memo[i][j];

//     }
// };


class Solution {
public:
    vector<vector<int>> dp;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
            int m = dungeon.size();
            int n = dungeon[0].size();
            // int res;
            dp = vector(m+1, vector<int>(n+1));
            dp[m-1][n-1] = dungeon[m-1][n-1] < 0 ? -dungeon[m-1][n-1] +1 :1;
            for(int i = m; i>=0; i--){
                for(int j= n; j>=0; j--){
                    if (i == m || j == n) {
                    dp[i][j] = INT_MAX;
                    continue;
                }
                    if (i == m - 1 && j == n - 1) {
                    continue;
                }

                    int res = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                    dp[i][j] = res <= 0?1: res;
                }
                
            }
            return dp[0][0];
    }
};//迭代

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp = vector(m+1, vector<int>(n+1));
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1] < 0 ? -dungeon[m - 1][n - 1] + 1 : 1;
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i == m || j == n) {
                    dp[i][j] = INT_MAX;
                    continue;
                }
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                int res = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = res <= 0 ? 1 : res;
            }
        }
        return dp[0][0];
    }
};//递归