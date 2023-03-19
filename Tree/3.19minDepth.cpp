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
//层次遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0;i<sz;i++){
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left == NULL && cur->right == NULL ) return depth;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};



