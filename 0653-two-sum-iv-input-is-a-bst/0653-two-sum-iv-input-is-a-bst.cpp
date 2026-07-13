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

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {

        while (node != NULL) {

            st.push(node);

            if (reverse == false) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
    }

    int next() {

        TreeNode* tempNode = st.top();
        st.pop();

        if (reverse == false) {
            pushAll(tempNode->right);
        }
        else {
            pushAll(tempNode->left);
        }

        return tempNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        BSTIterator left(root, false);   // Inorder Iterator
        BSTIterator right(root, true);   // Reverse Inorder Iterator

        int i = left.next();
        int j = right.next();

        while (i < j) {

            if (i + j == k) {
                return true;
            }
            else if (i + j < k) {
                i = left.next();
            }
            else {
                j = right.next();
            }
        }

        return false;
    }
};