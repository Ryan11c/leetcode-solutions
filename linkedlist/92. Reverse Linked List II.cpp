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
One of my favorite linked list question. 
*/
 
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;
            for(int i = 0; i < left - 1; i++){
                prev = prev->next;
            }
            ListNode* cur = prev->next;
            for(int i = 0; i < right - left; i++){
                ListNode* forw = cur->next;
                cur->next = forw->next;
                forw->next = prev->next;
                prev->next = forw;
            }
            ListNode* res = dummy->next;
            delete dummy;
            return res;
        }
};
    
