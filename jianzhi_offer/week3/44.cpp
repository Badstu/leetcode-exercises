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

    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> tmp;
        bool zigzag = false;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while(q.size()){
            auto t = q.front();
            q.pop();

            if(!t){
                if(zigzag) reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
                tmp.clear();

                if(q.empty()) break; //如果你是最后一个nullptr，不判断q为空的话会一直加nullptr
                q.push(nullptr);
                zigzag = !zigzag;
            } else{
                tmp.push_back( t->val );
                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
        }
        return res;
    }
};