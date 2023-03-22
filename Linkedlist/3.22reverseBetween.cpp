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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }
private:
    ListNode* suc;
    ListNode* reverseN(ListNode* head, int n) {
        if(n == 1){
            suc = head->next;
            return head;   // base case n==1 返回自身节点，同时记录后驱节点
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = suc;
        return last;        
    }

 };