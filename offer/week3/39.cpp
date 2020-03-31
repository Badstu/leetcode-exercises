/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(!root) return true;

//         return isSame(root -> left, root -> right);
//     }

//     bool isSame(TreeNode* a, TreeNode* b){
//         if(!a || !b) return !a && !b;
//         if(a->val == b->val && isSame(a->left, b->right) && isSame(a->right, b->left)) return true;
//         return false;
//     }
// };

/*
非递归实现中序遍历
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        stack<TreeNode*> left;
        stack<TreeNode*> right;

        TreeNode* lc = root -> left;
        TreeNode* rc = root -> right;

        while(lc || rc || left.size()){
            while(lc && rc){
                left.push(lc);
                right.push(rc);
                lc = lc -> left;
                rc = rc -> right;
            }
            if(lc || rc) return false;

            lc = left.top(), rc = right.top();
            left.pop(), right.pop();
            if(lc -> val != rc -> val) return false;
            lc = lc -> right, rc = rc -> left;
        }
        return true;
    }
};
