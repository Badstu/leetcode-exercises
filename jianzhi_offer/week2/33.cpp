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
    ListNode* findKthToTail(ListNode* h, int k) {
        auto p = h;
        int n = 0;
        while(p){
            n++;
            p = p -> next;
        }

        if(k > n || !n) return 0;
        p = h;
        for(int i = 0; i < n - k + 1; i++){
            p = p -> next;
        }
        return p;
    }
};

