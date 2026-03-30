// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // process current node here
        if (prev && prev->val > root->val) {
            if (first == NULL) { 
            first = prev; 
            second = root;
            } else  second = root;
        } else

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
         inorder(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

