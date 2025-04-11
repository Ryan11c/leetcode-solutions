#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Loop through the linked lists and add the nodes together. Keep track of remainder and carry for the next
nodes. We also use a dummy to store the new linked list output.
*/
 
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0);
            ListNode* cur = dummy;
            int total = 0, carry = 0;
            while(l1 || l2 || carry){
                total = carry;
                if(l1){
                    total += l1->val;
                    l1 = l1->next;
                }
                if(l2){
                    total += l2->val;
                    l2 = l2->next;
                }
                int num = total % 10;
                carry = total / 10;
                dummy->next = new ListNode(num);
                dummy = dummy->next;
            }
            ListNode* output = cur->next;
            delete cur;
            return output;
        }
};    