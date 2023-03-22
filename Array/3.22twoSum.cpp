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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left+1, right+1};
            if (sum < target) left++;
            if (sum > target) right--;
        }
        return {-1, -1};
    }
};