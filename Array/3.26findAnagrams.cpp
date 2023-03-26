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
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left=0, right=0;
        unordered_map<char, int> window, need;
        for (char c: p) need[c] ++;
        int valid=0;
        // int index = 0;
        while(right < s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            while(right - left >= p.size()){
                if(valid == need.size()) res.push_back(left);
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d]== need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};