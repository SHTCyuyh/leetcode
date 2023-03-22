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
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            if(nums[fast] != 0){
                nums[slow] = nums[fast];
                slow ++;
            }
            fast ++;
        }
        for(int i=slow; i<nums.size();i++){
            nums[i] = 0;
        }
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int fast = 0, slow = 0;
        while(fast < nums.size()){
            if (nums[fast] != val){
                nums[slow] = nums[fast];
                slow ++;
            }
            fast ++;
        }
        return slow;
    }
};