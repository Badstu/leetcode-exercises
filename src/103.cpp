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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> tmp;
        int times = 0;

        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            auto t = q.front();
            q.pop();

            if(!t){
                if(times % 2 == 1){
                    reverse(tmp.begin(), tmp.end());
                }
                res.push_back(tmp);
                tmp.clear();
                if(q.size()) q.push(NULL);
                times ++;
                continue;
            }

            tmp.push_back(t -> val);
            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }

        return res;
    }
};