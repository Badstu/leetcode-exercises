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
    int max_times = 0, cur_times = 0;
    int cur_element, old_element = INT_MIN;

    vector<int> res;

    vector<int> findMode(TreeNode* root) {
        if(!root) return res;
        dfs(root);

        return res;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root -> left);

        int cur_element = root -> val;
        if(cur_element != old_element){
            cur_times = 0;
        }
        cur_times++;
        if(cur_times > max_times){
            max_times = cur_times;
            res.clear();
            res.push_back(cur_element);
        } else if(cur_times == max_times) {
            res.push_back(cur_element);
        }

        old_element = cur_element;
        dfs(root -> right);

    }
};