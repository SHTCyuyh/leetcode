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
    int numDistinct(string s, string t) {
        memo =  vector<vector<int>>(s.length(), vector<int>(t.length(), -1));
        return dp(s,0,t,0);
    }
    vector<vector<int>> memo;
    int dp(string& s, int i, string& t, int j){
        int m = s.length(), n = t.length();
        if(j == n) return 1;
        if(n-j > m-i) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int res = 0;
        if (s[i] == t[j]){
            res += dp(s, i + 1, t, j + 1) + dp(s, i + 1, t, j);
        }else{
            res += dp(s, i + 1, t, j);
        }
        memo[i][j] = res;
        return res;
    }
};




// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int m = s.size(), n = t.size();
//         if(m < n) return 0;
//         vector<vector<int>> dp(m+1, vector<int>(n+1,0)); // 其中 dp[i][j]表示在 s[i:]的子序列中t[j:] 出现的个数。
//         for(int i=0;i<=m; i++){
//             dp[i][n] = 1; 
//         }
//          for (int i = m - 1; i >= 0; i--) {
//             char sChar = s.at(i);
//             for (int j = n - 1; j >= 0; j--) {
//                 char tChar = t.at(j);
//                 if (sChar == tChar) {
//                     dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
//                 } else {
//                     dp[i][j] = dp[i + 1][j];
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };