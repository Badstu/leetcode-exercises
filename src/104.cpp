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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }


    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        return max(left, right) + 1;
    }
};