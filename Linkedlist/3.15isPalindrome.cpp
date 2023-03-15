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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL){  //判断是奇数还是偶数 偶数需要slow指向第二个中心
            slow = slow->next;
        }
        ListNode* left = head;
        ListNode* right = reverse(slow);
        while(right != NULL){
            if (right->val != left->val) return false;
            right = right->next;
            left = left->next;
        }
        return true;

    }

    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};
