/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
			int floor = -1, ceil = -1;

			while(root != NULL) {
				if(root->data == key) {
					floor = ceil = root->data;
					break;
				}
				else if(key < root->data) {
					ceil = root->data;
					root = root->left;
				}
				else {
					floor = floor->data;
					root = root->right;
				}
			}
			return {floor, ceil};
		}
};