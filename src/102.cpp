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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> tmp;
        if(!root) return res;

        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            auto t = q.front();
            q.pop();

            if(!t){
                res.push_back(tmp);
                tmp.clear();
                if(q.size()) q.push(NULL); //这步很关键
                continue;
            }

            tmp.push_back(t -> val);
            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }

        return res;
    }
};