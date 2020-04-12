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
    int treeDepth(TreeNode* root) {
        int ans = dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root -> left);
        int right = dfs(root -> right);
        int res = max(left, right) + 1;

        return res;
    }
};