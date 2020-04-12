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
    vector<int> printFromTopToBottom(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            auto t = q.front();
            res.push_back(t->val);
            q.pop();

            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }
        return res;
    }
};