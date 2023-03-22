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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *a = head;
        ListNode *b = head;
        for(int i=0; i<k; i++){
            if(b == NULL)   
                return head;
            b = b->next;
        }  // 如果小于K 则直接返回
        ListNode *newHead = reverse(a, b); //新的头在第k个
        a->next = reverseKGroup(b,k);  // a成为连接下一组k的末位节点
        return newHead;
    }
private:
    ListNode* reverse(ListNode* first, ListNode *last) {
        ListNode *cur, *pre, *nxt;
        cur = first;
        pre = NULL;
        while(cur != last){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
    return pre;
    }
 };