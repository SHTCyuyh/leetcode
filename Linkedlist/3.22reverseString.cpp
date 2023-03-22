#include <stdio.h>
#include <vector>
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
    void reverseString(vector<char>& s) {
        char temp;
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left ++;
            right --;
        }
    }
};