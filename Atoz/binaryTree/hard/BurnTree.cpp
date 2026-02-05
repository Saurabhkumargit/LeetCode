// Minimum time taken to burn the BT from a given Node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode*& targetNode, int start) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->data == start)
                targetNode = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int timeToBurnTree(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* targetNode = nullptr;

        markParents(root, parent, targetNode, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burnedSomething = false;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    burnedSomething = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !visited[curr->right]) {
                    burnedSomething = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if (parent[curr] && !visited[parent[curr]]) {
                    burnedSomething = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            if (burnedSomething) time++;
        }

        return time;
    }
};
