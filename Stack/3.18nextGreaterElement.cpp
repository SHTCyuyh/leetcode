#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std; 



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater = nextgreter(nums2);
        map<int,int> greatmap;
        for (int i=0;i<nums2.size();i++){
            greatmap[nums2[i]] = greater[i];
        }
        vector<int> res(nums1.size());
        for (int i=0;i<nums1.size();i++){
            res[i] = greatmap[nums1[i]];
        }
        return res;

    }
    vector<int> nextgreter(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for (int i=n-1;i>=0;i--){
            while(!s.empty()&& s.top() <= nums[i]){
                s.pop();
            }
            res[i] = s.empty()? -1:s.top();
            s.push(nums[i]);
        }
        return res;
    }
};



