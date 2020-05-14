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
    bool isValidBST(TreeNode* root) {
		// if(!root) return true;
		long long max_element = (long long) INT_MAX+10, min_elemet = (long long)INT_MIN-10; 
		return dfs(root, max_element, min_elemet);
    }

	bool dfs(TreeNode* root, long long max_e, long long min_e){
		if(!root) return true;

		int t = root -> val;
		if(t >= max_e || t <= min_e) return false;
		return dfs(root -> left, t, min_e) && dfs(root -> right, max_e, t);
	}
};