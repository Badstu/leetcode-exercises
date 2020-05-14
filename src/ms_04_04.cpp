/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool flag = true;
    bool isBalanced(TreeNode* root) {
		if(!root) return true;
		getHeight(root);
		return flag;
    }

	int getHeight(TreeNode* root){
		if(!root) return 0;

		int left = getHeight(root -> left);
		int right = getHeight(root -> right);

		if(abs(left - right) > 1) flag = false;
		int h = max(left, right) + 1;
		return h;
	}
};