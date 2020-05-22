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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
		return buildSubTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

	TreeNode* buildSubTree(vector<int>& preorder, int pl, int pr, vector<int>&inorder, int il, int ir){
		int v = preorder[pl];
		TreeNode* root = new TreeNode(v);
		if(pl == pr) return root;
		
		int i = il;
		for(; i <= ir; i++){
			if(inorder[i] == v) break;
		}

		int nums_left = i - il;
		int nums_right = ir - i;
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		if(nums_left) left = buildSubTree(preorder, pl+1, pl+nums_left, inorder, il, i-1);
		if(nums_right) right = buildSubTree(preorder, pl+nums_left+1, pl+nums_left+nums_right, inorder, i+1, ir);
		
		root -> left = left;
		root -> right = right;

		return root;
	}
};