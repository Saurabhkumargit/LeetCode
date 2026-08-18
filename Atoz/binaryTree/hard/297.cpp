// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string result;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
            }

            // Right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->right = new TreeNode(stoi(item));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// Revision (1)
class Codec {
public:

    void serializeHelper(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(root->val) + ",";

        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    string serialize(TreeNode* root) {
        string result;

        serializeHelper(root, result);

        return result;
    }


    TreeNode* deserializeHelper(stringstream& ss) {
        string value;

        getline(ss, value, ',');

        if (value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return deserializeHelper(ss);
    }
};