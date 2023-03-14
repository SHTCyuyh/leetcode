#include <stdio.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//难点在于不能同时到达交点，如果把链表拼接起来就能实现
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(p1 != p2){
            if (p1 == NULL) p1 = headB;  //将双链表转换成为单链表
            else p1 = p1->next;
            if (p2 == NULL) p2 = headA;
            else p2 = p2->next;
        }
     return p1;
    }
};