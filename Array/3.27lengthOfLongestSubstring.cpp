#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left=0, right=0;
        int res = 0;
        while(right < s.size()){
            char c = s[right];
            window[c]++;
            right++;
            while(window[c]>1){
                char d = s[left];
                left++;
                window[d]--;
            }
            res = max(res, (right-left));
        }
        return res;
    }
};