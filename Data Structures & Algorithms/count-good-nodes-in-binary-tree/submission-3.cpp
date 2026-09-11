/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int count =0;
int dfs(TreeNode *root , int maxval){
    if(root==nullptr) return 0;
    if(root->val>=maxval){
        count++;

    }
    maxval = max(maxval,root->val);
    dfs(root->left,maxval);
    dfs(root->right,maxval);
    return count;
}
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        return dfs(root,root->val);
    }
};
