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
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n ;i++) dp[i][i]=0;
        for(int i =n-1;i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else{
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j-1]+1);
                }
            }
        } 
        return dp[0][n-1];
    }
};



// class Solution {
// public:
//     int minInsertions(string s) {
//         int n = s.size();
//         int p = longestPalindromeSubseq(s);
//         return n - p;

//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for(int i=0;i<n;i++) dp[i][i] = 1;
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i + 1; j < n; j++) {
//                 if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] +2;
//                 else{
//                     dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[0][n-1];
//         }
// };
