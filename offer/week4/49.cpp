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
    TreeNode* convert(TreeNode* root) {
        if(!root) return nullptr;
        auto res = dfs(root);
        return res.first;
    }

    pair<TreeNode*, TreeNode*> dfs(TreeNode* root){
        if(!root->left && !root->right) return {root, root};
        if(root -> left && root -> right){
            auto lside = dfs(root->left), rside = dfs(root->right);
            lside.second -> right = root, root -> left = lside.second;
            root -> right = rside.first, rside.first -> left = root;
            return {lside.first, rside.second};
        }
        if(root -> left){
            auto lside = dfs(root -> left);
            lside.second -> right = root, root -> left = lside.second;
            return {lside.first, root};
        }
        if(root -> right){
            auto rside = dfs(root -> right);
            root -> right = rside.first, rside.first -> left = root;
            return {root, rside.second};
        }
    }

};