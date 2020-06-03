/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        if(head -> val == root -> val){
            if(dfs(head, root)) return true;
        }
        return isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        ListNode* p = head;
        if(!p) return true;
        if(!root || p -> val != root -> val) return false;
        return dfs(p->next, root->left) || dfs(p->next, root->right);
    }
};