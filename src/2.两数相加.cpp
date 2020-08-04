#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
        ListNode* head = dummy;

        int t = 0, carry = 0;
        while(l1 && l2){
            int a = l1 -> val, b = l2 -> val;
            t = a + b + carry;
            carry = t / 10;
            t = t % 10;
            ListNode* node = new ListNode(t);
            
            head -> next = node;
            head = head -> next;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1){
            t = l1 -> val + carry;
            carry = t / 10;
            t = t % 10;
            ListNode* node = new ListNode(t);
            head -> next = node;
            head = head -> next;
            l1 = l1 -> next;
        }

        while(l2){
            t = l2 -> val + carry;
            carry = t / 10;
            t = t % 10;
            ListNode* node = new ListNode(t);
            head -> next = node;
            head = head -> next;
            l2 = l2 -> next;
        }

        if(carry){
            ListNode* node = new ListNode(carry);
            head -> next = node;
        }
        
        return dummy -> next;
    }
};
// @lc code=end

