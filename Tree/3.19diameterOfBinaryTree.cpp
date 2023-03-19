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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        int res = left + right;
       return max(res,
                max(diameterOfBinaryTree(root->left),
                    diameterOfBinaryTree(root->right)));

    }
    int maxdepth(TreeNode* root){
        if(root == NULL) return 0;
        int left = maxdepth(root->left);
        int rigth = maxdepth(root->right);
        return max(left,rigth)+1;
    }
};


//回溯
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return res;

    }
    int traverse(TreeNode* root){
        if(root == NULL) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        res = max(left+right,res);
        return max(left,right)+1;
    }
};





