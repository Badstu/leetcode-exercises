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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop_front();
            TreeNode* tmp = t -> left;
            t -> left = t -> right;
            t -> right = tmp;

            if(!t -> left) q.push(t -> left);
            if(!t -> right) q.push(t -> right);
        }

        return root;
    }
};