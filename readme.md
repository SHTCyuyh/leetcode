# Linked List
```
3.13 LRU（hash map + linked list）:
* Hash 存储链表节点，链表通过指针修改任意位置；
* LRU从表尾加，表头删，每次使用一次节点就更新对应节点到表尾。
3.13 mergeTwoLists(21):
* 链表c++中 p = p->next 表示往下移;
* 链接两个链表(p1,p2)只需要将p最后的next赋值给p1(p->next = p1)；
* `虚拟头结点`可以避免处理空指针
```
