#include <stdio.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            if (slow->val != fast->val){
                slow->next = fast;
                slow = slow->next; //slow and fast be the same node
            }
            fast = fast->next;
        }
        slow->next = NULL;
        return head;
   
    }
 };