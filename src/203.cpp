/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        auto p = dummy;
        while(p -> next){
            auto ne = p -> next;
            if(ne -> val == val){
                p -> next = ne -> next;

            } else{
                p = p -> next;
            }
        }
        return dummy -> next;
    }
};