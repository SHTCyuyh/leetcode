#include <stdio.h>
#include <vector>
#include <string>
#include <assert.h>
#include<unordered_map>
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
    string minWindow(string s, string t) {
        unordered_map<char, int> window,need;
        for (char c:t) need[c]++;
        int left=0, right=0;
        int len = INT_MAX;
        int valid = 0;
        int start = 0;
        while(right < s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            while(valid == need.size()){
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX? "": s.substr(start, len);
    }
};