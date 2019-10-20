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
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;
        int len2 = 1;
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *result = new ListNode(-1);

        while(p->next != NULL){
            len1++;
            p = p->next;
        }
        while(q->next != NULL){
            len2++;
            q = q->next;
        }

        if(len1 > len2){
            for (int i = 0; i < len1 - len2; i++){
                q->next = new ListNode(0);
                q = q->next;
            }
        } else{
            for (int i = 0; i < len2 - len1; i++){
                p->next = new ListNode(0);
                p = p->next;
            }
        }

        int sum = 0;
        int carry = 0;
        p = l1;
        q = l2;
        ListNode *w = result;

        while (p->next != NULL){
            sum = p->val + q->val + carry;
            w->next = new ListNode(sum % 10);

            carry = sum / 10;
            p = p->next;
            q = q->next;
            w = w->next;
        };

        sum = p->val + q->val + carry;
        w->next = new ListNode(sum % 10);
        w = w->next;
        carry = sum / 10;
        

        if (carry == 1){
            w->next = new ListNode(1);
            w = w->next;
        }

        w = result;
        while(w->next != NULL){
            cout << w->next->val;
            w = w->next;
        }

        ListNode *ptrDelete = result;
        result = result->next;
        delete ptrDelete;
        return result;
    }
};

class Solution2{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode *result = new ListNode(-1);
        ListNode *w = result;
        while(l1->next != NULL || l2->next != NULL){
            sum = 0;
            if(l1->next != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2->next != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;

            w->next = new ListNode(sum % 10);
            w = w->next;
            carry = sum / 10;
        }
        if(carry == 1){
            w->next = new ListNode(1);
            w = w->next;
        }

        w = result;
        while(w->next != NULL){
            cout << w->next->val;
            w = w->next;
        }
        cout << w->next->val;
    }
};

// @lc code=end

