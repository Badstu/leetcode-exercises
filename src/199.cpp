/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// DFS
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int depth){
        if(!root) return;

        if(res.size() <= depth)
            res.push_back(root -> val);
        else
            res[depth] = root -> val;

        dfs(root -> left, depth+1);
        dfs(root -> right, depth+1);

    }

};

// BFS
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;
        queue<TreeNode*> que;
        queue<int> depth_que;

        que.push(root);
        depth_que.push(0);

        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            int depth = depth_que.front();
            depth_que.pop();

            if(res.size() <= depth){
                res.push_back(node -> val);
            } else{
                res[depth] = node -> val;
            }

            if(node -> left) que.push(node -> left), depth_que.push(depth+1);
            if(node -> right) que.push(node -> right), depth_que.push(depth+1);
        }
        return res;
    }
};