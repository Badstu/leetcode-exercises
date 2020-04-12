/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        if(!head) return nullptr;

        for(auto p = head; p;){
            auto newp = new ListNode(p -> val);
            auto t = p -> next;
            p -> next = newp;
            newp -> next = t;
            p = t;
        }

        for(auto p = head; p; p = p -> next){
            if(p->random){
                p -> next -> random = p -> random -> next;
            }
            p = p -> next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        for(auto p = head; p; p = p -> next){
            cur -> next = p -> next;
            cur = cur -> next;
            p -> next = p -> next -> next; //把原链表和复刻链表拆开
        }

        return dummy -> next;
    }
};
