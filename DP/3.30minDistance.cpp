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
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        memo = vector(word1.size(),vector<int>(word2.size(),-1));
        return dp(word1,n-1,word2,m-1);
    }
    
    int dp(string &s1, int i, string& s2, int j){
        if(j == -1) return i+1;
        if(i == -1) return j+1;
        if(memo[i][j] != -1) return memo[i][j];
        if(s1[i] == s2[j]){
            memo[i][j] = dp(s1,i-1,s2,j-1);
        }else{
            memo[i][j] = min3(
                dp(s1,i-1,s2,j-1)+1,
                dp(s1,i,s2,j-1)+1,
                dp(s1,i-1, s2, j)+1
            );
        }
        return memo[i][j];
    }
    int min3(int a, int b, int c){
        return min(min(a,b), c);
    }
};//自顶向下


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
         int dp[m + 1][n + 1];
         dp[0][0] = 0;
        for(int i =0; i<m; i++) dp[0][i] = i;
        for(int i =0; i<n; i++) dp[i][0] = i;
        for(int i=1; i<=m; i++){
            for(int j =1;j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] =  dp[i - 1][j - 1];
                else{
                    dp[i][j] = min3(
                        dp[i-1][j]+1,
                        dp[i-1][j-1] +1,
                        dp[i][j-1]+1
                    );
                }
            }
        }
        return dp[m][n];
    }
        int min3(int a, int b, int c){
        return min(min(a,b), c);
    }
};//自底向上

