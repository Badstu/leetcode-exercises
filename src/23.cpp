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

    ListNode* mergeTwoLists(ListNode* ha, ListNode* hb){
        ListNode* dummy = new ListNode(-1);
        auto head = dummy;
        while(ha && hb){
            if(ha -> val <= hb -> val){
                head -> next = ha;
                ha = ha -> next;
                head = head -> next;
            } else{
                head -> next = hb;
                hb = hb -> next;
                head = head -> next;
            }
        }
        if(ha) head -> next = ha;
        if(hb) head -> next = hb;
        return dummy -> next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        int mid = l + r >> 1;
        auto p = mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
        return p;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        auto p = merge(lists, 0, n - 1);
        return p;
    }
};