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
    int fib(int n) {
        if(n == 0) return 0;
        int* dp = new int[n+1];
        dp[0] = 0;dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     unordered_map<int, int> mp;
//     int fib(int n) {
//         return dp(mp,n);
//     }
//     int dp( unordered_map<int, int> &mp, int n){
//         if(n==0 )return 0;
//         if(n==1) return 1;
//         if(mp.count(n)) {
//             return mp[n];}
//         mp[n] = dp(mp, n-1) + dp(mp, n-2);
//         return mp[n];
//     }
// };



// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0) return 0;
//         if(n == 1) return 1;
//         else{
//             return fib(n-1) + fib(n-2);
//         }
//     }
// };