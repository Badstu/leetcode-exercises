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
    TreeNode* ans;

    TreeNode* kthNode(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    TreeNode* dfs(TreeNode* root, int &k){
        if(!k || !root) return NULL;

        dfs()
    }


};