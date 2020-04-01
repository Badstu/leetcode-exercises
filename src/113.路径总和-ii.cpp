/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
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
    vector<vector<int>> path;
    vector<int> temp;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // if(!root) return NULL;
        dfs(root, sum);

        return path;
    }

    void dfs(TreeNode* p, int sum){
        if(!p) return;

        sum -= p -> val;
        temp.push_back(p -> val);

        if(!p -> left && !p -> right && !sum){
            path.push_back(temp);
            //这两步不用管，因为空节点在下一步会判掉
            temp.pop_back();
            return;
        }
        
        dfs(p -> left, sum);
        dfs(p -> right, sum);

        sum += p -> val;
        temp.pop_back();
        return;
    }


};
// @lc code=end

