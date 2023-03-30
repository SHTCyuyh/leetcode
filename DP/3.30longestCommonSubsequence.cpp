#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
# include <string.h>
#include<iostream>
#include<queue>
#include<stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};


// class Solution {
// public:
//     vector<vector<int>> memo;
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         memo = vector(m, vector<int>(n,-1));
//         return dp(text1,m-1,text2,n-1);
//     }
//     int dp(string s1, int i , string s2, int j){
//         int m = s1.size(), n = s2.size();
//         if(j == -1 || i == -1)  return 0;
//         if(memo[i][j] != -1) return memo[i][j];
//         if(s1[i] == s2[j]){
//             memo[i][j] = dp(s1,i-1,s2,j-1) + 1;
//         }else{
//             memo[i][j] = max(dp(s1,i-1,s2,j),dp(s1,i,s2,j-1));
//         }
//         return memo[i][j];

//     }
// };