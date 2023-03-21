#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std; 


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int missing;
        int dup;
        int n = nums.size();
        for (int i=0; i<n ; i++){
            int key = nums[i]; 
            mp[key]++;
        }
        for (int i=1; i<=n ; i++){
            int count = mp[i];
            if (count == 0)
                missing = i;
            if (count == 2)
                dup = i;
        }
        return {dup, missing};
    }
};

// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         vector<int> errorNums(2);
//         int n = nums.size();
//         unordered_map<int, int> mp;
//         for (auto& num : nums) {
//             mp[num]++;
//         }
//         for (int i = 1; i <= n; i++) {
//             int count = mp[i];
//             if (count == 2) {
//                 errorNums[0] = i;
//             } else if (count == 0) {
//                 errorNums[1] = i;
//             }
//         }
//         return errorNums;
//     }
// };


