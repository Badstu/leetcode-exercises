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
		stack<int> s1, s2;
		auto p = l1, q = l2;
		while(p){
			s1.push(p -> val);
			p = p -> next;
		}

		while(q){
			s2.push(q -> val);
			q = q -> next;
		}

		ListNode* dummy = new ListNode(-1);
		auto head = dummy;

		int carry = 0;
		while(s1.size() || s2.size()){
			int t1 = 0, t2 = 0;
			if(s1.empty()){
				t2 = s2.top();
				s2.pop();
			} else if(s2.empty()){
				t1 = s1.top();
				s1.pop();
			} else{
				t1 = s1.top();
				t2 = s2.top();
				s1.pop();
				s2.pop();	
			}
            
			int value = t1 + t2 + carry;
			carry = value / 10;
			ListNode* tmp = new ListNode(value % 10);
			tmp -> next = head -> next;
			head -> next = tmp;
            
		}
		if(carry){
			ListNode* tmp = new ListNode(carry);
			tmp -> next = head -> next;
			head -> next = tmp;
		}

		return dummy -> next;
    }
};