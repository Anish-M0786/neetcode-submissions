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
int dia(TreeNode*root,int &diameter){
    if(root==nullptr) return 0;
    int leftl = dia(root->left,diameter);
    int rightl = dia(root->right,diameter);
     diameter = max(diameter,leftl+rightl);

    return 1 + max(leftl,rightl);
}
    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;
        dia(root,diameter);

        return diameter;
        
    }
};
