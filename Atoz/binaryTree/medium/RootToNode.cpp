// Print root to node path in BT

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
class Solution{
    public:
    
    void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& ans) {
        if (!node) return;
        
        path.push_back(node->data);
        
        if (!node->left && !node->right) {
            ans.push_back(path);
        } 
        else {
            dfs(node->left, path, ans);
            dfs(node->right, path, ans);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(root, path, ans);
        return ans;
    }
};
