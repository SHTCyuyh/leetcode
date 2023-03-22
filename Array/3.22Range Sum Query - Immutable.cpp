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

class NumArray {
public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size()+1);
        for (int i=1; i<preSum.size(); i++){
            preSum[i] = preSum[i-1] + nums[i-1]; 
        }
    }
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
private:
    vector<int> preSum;
};


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        preSum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i =1; i<=m; i++){
            for (int j=1; j<=n;j++){
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i - 1][j - 1] - preSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    return preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];
    }
private:
    vector<vector<int>> preSum;
};