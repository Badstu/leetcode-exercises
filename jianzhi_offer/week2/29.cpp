#include <iostream>

using namespace std;

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
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* h = new ListNode(-1);
        h -> next = head;
        ListNode* p = h;
    
        while(p -> next){
            ListNode* q = p -> next;
            while(q -> next && q -> val == q -> next -> val)
                q = q -> next;
                
            if(q == p -> next)
                p = q;
            else p -> next = q -> next;
        }
        return h -> next;
    }
};
