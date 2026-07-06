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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        height(root,maxDia);
        return maxDia;
    }
    int height(TreeNode*root,int &maxDia){
        if(root==nullptr){
            return 0;
        }
        int lh = height(root->left,maxDia);
        int rh = height(root->right,maxDia);
        maxDia=max(maxDia,lh+rh);
        return 1+ max(lh,rh);
    }
};