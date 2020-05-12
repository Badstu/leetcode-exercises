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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;

        int left = pathSum(root -> left, sum);
        int right = pathSum(root -> right, sum);
        int r = dfs(root, sum);
        return left + right + r;
    }

    int dfs(TreeNode *root, int sum){
        if(!root) return 0;
        int flag = 0;
        int val = root -> val;
        if(sum - val == 0){
            flag = 1;
        }

        int left = dfs(root -> left, sum - val);
        int right = dfs(root -> right, sum - val);

        return flag + left + right;
    }
};