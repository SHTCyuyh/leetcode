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
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        int count[256] = {0};
        bool inStack[256] = {false};
        for(char c: s) count[c]++;
        for(char c: s){
            count[c]--;
            if (inStack[c]) continue;
            while(!stk.empty() && stk.top()>c){
                if(count[stk.top()] == 0) break;
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true; 
        }
        string res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
