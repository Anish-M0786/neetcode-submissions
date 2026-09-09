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
    int preIndex = 0;
    unordered_map<int,int>inordermp;
    TreeNode *arraytotree(vector<int>&preorder,int left,int right){
        if(left>right) return nullptr;
        int rootval = preorder[preIndex++];
        TreeNode *root = new TreeNode(rootval);
        int rootpos = inordermp[rootval];
        root->left = arraytotree(preorder,left,rootpos-1);
        root->right = arraytotree(preorder,rootpos+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        inordermp.clear();
        for(int i=0;i<inorder.size();i++){
            inordermp[inorder[i]] = i;
        }
        return arraytotree(preorder,0,preorder.size()-1);
    }
};
