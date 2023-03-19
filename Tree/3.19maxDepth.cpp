#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/////递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return left_depth>right_depth? left_depth+1:right_depth+1;
    }
};

/// 回溯
class Solution {
public:
    int depth = 0;
    int res = 0;
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if (root == NULL) return;
        depth++; // 每层会使深度+1 前序位置
        if(root->left == NULL && root->right == NULL){
            res = max(res, depth);
        }//到达叶子节点更新最大深度
        traverse(root->left);
        traverse(root->right);
        depth--;// 到达后序位置，也就是回溯过程深度会-1
    }
};


