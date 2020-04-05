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
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> findPath(TreeNode* root, int sum) {
        if(!root) return res;
        ispath(root, sum);

        return res;
    }

    void ispath(TreeNode* root, int sum){
        if(!root) return;

        sum -= root -> val;
        path.push_back(root -> val);

        if(!root->left && !root->right && sum == 0){
            res.push_back(path);
            // path.clear();
        }
    
        ispath(root -> left, sum);
        ispath(root -> right, sum);
        path.pop_back();

        return;
    }


};