# Linked List
```
3.13 LRU（hash map + linked list）:
```
* Hash 存储链表节点，链表通过指针修改任意位置；
* LRU从表尾加，表头删，每次使用一次节点就更新对应节点到表尾。

```
3.13 mergeTwoLists(21):
```
* 链表c++中 p = p->next 表示往下移;
* 链接两个链表(p1,p2)只需要将p最后的next赋值给p1(p->next = p1)；
* `虚拟头结点`可以避免处理空指针


```
3.13 deleteDuplicates(83):
```
* 双指针快慢（一般是单链表）处理去重等问题
* 就地删除slow->next = fast (本科读法，fast成为slow的后继，也就是说把slow与fast之间的元素断开了)
* 判定条件一般是所有元素遍历，也就是快指针结束
* 临界条件注意空指针的处理

```
3.13 hasCycle(141):
```
* 判断是否有环可以用快慢指针，快指针每次前进两个，慢指针前进一个，相遇则有环；
* 判断环的起点，则相遇后让一个指针回到起点，然后同步向前，再次相遇则是环起点（设两个指针相遇慢走k，则快走2k[在k步一定是环的整数倍]；环起点在k-m处，则重新指向起点后，再次相遇就是环起点。）
* `注意c++中需要指定返回值的类型，需要匹配！！！`
