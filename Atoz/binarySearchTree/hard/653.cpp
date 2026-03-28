// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    bool dfs(TreeNode* node, unordered_set<int>& seen, int k) {
        if (node == NULL) return false;

        int x = node->val;

        if (seen.count(k - x)) return true;

        seen.insert(x);

        return dfs(node->left, seen, k) || dfs(node->right, seen, k);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, seen, k);
    }
};