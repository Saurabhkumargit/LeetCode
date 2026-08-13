// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameter = 0;

    int depth(TreeNode* node) {
        if (!node) return 0;

        int left = depth(node->left);
        int right = depth(node->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};


// Revision (1)
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
    int diameter = 0;
    
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        diameter = max(diameter, leftheight + rightheight);

        return 1 + max(leftheight, rightheight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};