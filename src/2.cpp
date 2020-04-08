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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        auto head = dummy;

        auto p = l1, q = l2;
        int t = 0, carry = 0;
        while(p && q){
            t = p -> val + q -> val + carry;
            carry = t / 10;
            head -> next = new ListNode(t % 10);
            head = head -> next;
            p = p -> next;
            q = q -> next;
        }

        while(p){
            cout << p -> val << endl;
            t = p -> val + carry;
            cout << t << endl;
            carry = t / 10;
            head -> next = new ListNode(t % 10);
            head = head -> next;
            p = p -> next;
        }

        while(q){
            t = q -> val + carry;
            carry = t / 10;
            head -> next = new ListNode(t % 10);
            head = head -> next;
            q = q -> next;
        }
        if(carry) head -> next = new ListNode(carry);

        return dummy -> next;
    }
};