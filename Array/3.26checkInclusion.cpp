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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window,need;
        int left = 0, right = 0;
        int valid = 0;
        for(char s: s1) need[s]++;
        while(right < s2.size()){
            char c = s2[right];
            right ++;
            if (need.count(c)){
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }
            while(right - left >= s1.size()){
                if (valid == need.size()) return true;
                char d = s2[left];
                left ++;
                if (need.count(d)){
                    if(window[d] == need[d])valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};