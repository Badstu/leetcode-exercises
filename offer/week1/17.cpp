#include <iostream>
#include <vector>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> res;
        while(head){
            int val = head -> val;
            res.push_back(val);
            head = head -> next;
        }

        return vector<int> (res.rbegin(), res.rend());
    }
};
