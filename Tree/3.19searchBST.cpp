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

// 递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int target) {
        if (root == NULL) {
            return NULL;
        }
        // 去左子树搜索
        if (root->val > target) {
            return searchBST(root->left, target);
        }
        // 去右子树搜索
        if (root->val < target) {
            return searchBST(root->right, target);
        }
        return root;
    }
};


// //回溯
// class Solution {
// public:
//     int searchBST(TreeNode* root) {
//     }
// };





