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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;//链表为空或者只有一个节点直接返回
        ListNode* last = reverseList(head->next);//递归，解决递归不能跳进递归
        head->next->next = head;
        head->next = NULL;
        return last;
    }
 };