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
    unordered_map<char, vector<int>> indexlist;
    vector<vector<int>> dp;
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();
        dp = vector<vector<int>>(m+1, vector<int>(n+1));
        for(int i=0; i<m; i++){
            char c = ring[i];
            indexlist[c].push_back(i);
            dp[i][n] = 0;
        }
        for(int j = n-1; j>=0; j--){
            for(int i=0 ; i<m; i++){
                int res = INT_MAX;
                for(int k : indexlist[key[j]]){
                    int step = min(abs(k-i), abs(m-(abs(k-i))));
                    int d_i_j = dp[k][j+1]  + step +1;
                    res = min(res , d_i_j);
                }
                dp[i][j] = res;

            }
        }
    return dp[0][0];
    }
}; //迭代


// class Solution {
// public:
//     unordered_map<char, vector<int>> indexlist;
//     vector<vector<int>> memo;
//     int findRotateSteps(string ring, string key) {
//         int m = ring.size(), n = key.size();
//         memo = vector<vector<int>>(m, vector<int>(n, 0));
//         for(int i=0; i<m; i++){
//             char c = ring[i];
//             indexlist[c].push_back(i);
//         }
//         return dp(ring, 0, key, 0);
//     }

//     int dp(string ring, int i, string key, int j){
//         if(j == key.size()) return 0;
//         // if(i == ring.size())
//         if(memo[i][j] != 0) return memo[i][j];
//         int n = ring.size();
//         int res = INT_MAX;
//         for(int k:indexlist[key[j]]){
//             // cout<< k<< endl;
//             int change =abs(i - k);
//             int change_r = n - change;
//             change  = min(change, change_r);
//             int subproblem = dp(ring, k, key, j+1);
//             res = min((subproblem + change +1),res);
//         }
//         memo[i][j] = res;
//         return memo[i][j];
//     }
// }; //递归