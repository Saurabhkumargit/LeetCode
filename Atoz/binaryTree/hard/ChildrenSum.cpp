// Children Sum Property in Binary Tree

/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if (root == NULL) return true;
        
        if (root->left == NULL && root->right == NULL)
            return true;
        
        int leftVal = 0, rightVal = 0;
        
        if (root->left != NULL)
            leftVal = root->left->val;
        
        if (root->right != NULL)
            rightVal = root->right->val;
        
        return (root->val == leftVal + rightVal) &&
               checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }
};

