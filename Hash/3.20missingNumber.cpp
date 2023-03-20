#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<unordered_set>
using namespace std; 


////位运算
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++){
            res ^= nums[i];
        }
        for (int i=0;i<=n;i++){
            res ^= i;
        }
        return res;
    }
};

//hash
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }
        int missing = -1;
        for (int i = 0; i <= n; i++) {
            if (!set.count(i)) {
                missing = i;
                break;
            }
        }
        return missing;
    }
};

