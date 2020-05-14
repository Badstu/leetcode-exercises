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
	bool flag;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

    }

	TreeNode* dfs(TreeNode* root){
		if(!root) return NULL;
		if(root -> right) return root -> right;
		if(flag == true) return 
	}

};