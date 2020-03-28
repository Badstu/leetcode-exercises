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
    ListNode *entryNodeOfLoop(ListNode *head) {
        if(!head || !head -> next) return 0;
        auto i = head;
        auto j = head;

        while(j){
            i = i -> next;
            j = j -> next;
            if(j) j = j -> next;
            else return 0;
            
            if(i == j){
                i = head;
                break;
            }
        }
        if(!j) return 0;

        while(i != j){
            i = i -> next;
            j = j -> next;
        }
        return j;
    }
};
