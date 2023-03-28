#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
#include<iostream>
#include<queue>
#include <algorithm>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    unordered_map<int, int> mp;
    int sz;
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        for(auto b: blacklist){
            mp[b] = 1000;
        }
        int last = n-1;
        for (auto b: blacklist){
            if(b >= sz) continue;
            else{
                while(mp.count(last)){
                    last--;
                }
            }
            mp[b] = last;
            last--;
        }
    }
    
    int pick() {
        int index = rand()%sz;
        if(mp.count(index)) return mp[index];
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */