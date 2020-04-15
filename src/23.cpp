#include <bits/stdc++.h>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* dummy = new ListNode(-1);
        auto head = dummy;

        auto cur = lists[0];
        int n = lists.size();

        for(int i = 1; i < n; i++){
            auto p = lists[i];
            
            while(cur && p){
                if(cur -> val < p -> val){
                    head -> next = cur;
                    cur = cur -> next;
                } else{
                    head -> next = p;
                    p = p -> next;
                }
                head = head -> next;
            }

            if(cur) head -> next = cur;
            if(p) head -> next = p;

            cur = dummy -> next;
            head = dummy;
        }

        return dummy -> next;
    }
};