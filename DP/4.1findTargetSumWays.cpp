#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
#include<iostream>
#include<queue>
#include<stack>
#include <algorithm>
using namespace std;



// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码已经通过力扣的测试用例，应该可直接成功提交。

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        return dp(nums, 0, target);
    }

    // 备忘录
    unordered_map<string, int> memo;

    int dp(vector<int>& nums, int i, int remain) {
        // base case
        if (i == nums.size()) {
            if (remain == 0) return 1;
            return 0;
        }
        // 把它俩转成字符串才能作为哈希表的键
        string key = to_string(i) + "," + to_string(remain);
        // 避免重复计算
        if (memo.count(key)) {
            return memo[key];
        }
        // 还是穷举
        int result = dp(nums, i + 1, remain - nums[i]) + dp(nums, i + 1, remain + nums[i]);
        // 记入备忘录
        memo[key] = result;
        return result;
    }
};
// 详细解析参见：
// https://labuladong.github.io/article/?qno=494
