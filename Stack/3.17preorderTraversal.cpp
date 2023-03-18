#include<stack>
#include<string>
#include<vector>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL){
            return res;
        }
        res.push_back(root->val);  //push_back 对应的是vector ； push 对应squee和stack
        vector<int> left = preorderTraversal(root->left);
        res.insert(res.end(),left.begin(),left.end()); // vector.insert(位置，插入内容起，插入内容终)
        vector<int> right = preorderTraversal(root->right);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
}; // 递归



class Solution {
public:
    vector<int> res;
    void traverse(TreeNode* root){
        if (root == NULL) return;
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
}; // 



