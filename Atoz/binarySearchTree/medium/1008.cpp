//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& i, int min, int max) {
        if (i >= preorder.size())
            return NULL;

        int val = preorder[i];

        if (val < min || val > max)
            return NULL;

        TreeNode* root = new TreeNode(val);
        i++;

        root->left = build(preorder, i, min, val);
        root->right = build(preorder, i, val, max);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MIN, INT_MAX);
    }
};