/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return dfs(root, sum);
    }

    bool dfs(TreeNode* p, int sum){
        if(!p) return false;
        else{
            sum -= p -> val;
            if(!p -> left && !p -> right && sum == 0) return true; //如果是叶子节点，且路径和==sum return true;
            if(dfs(p -> left, sum) || dfs(p -> right, sum)) return true;
            sum += p -> val; //因为dfs出来的时候不会进行下一轮dfs，所以可以不用恢复现场，否则要恢复先尝
        }
        return false;
    }

};
// @lc code=end

