#include <stdio.h>
#include <vector>
#include <string>
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
    string longestPalindrome(string s) {
        string res = "";
        for (int i=0; i< s.length(); i++){
            string s1 = Palindrome(s,i,i);
            string s2 = Palindrome(s,i,i+1);
            res = res.length() > s1.length()? res:s1;
            res = res.length() > s2.length()? res:s2;
        }
        return res;

    }
    string Palindrome(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
};