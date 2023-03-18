# Stack
```
3.16ValidParentheses（20）
```
* 每个右括号')'的左边必须有一个左括号'('和它匹配;
* 只有单一括号可以用数目来判定
* 栈的基本操作：s.empty();s.top();s.pop();s.push();s.size().
  

```
3.17preorderTraversal（144）
```
* vector.push_back()表示在动态数组最后插入，vector.insert(位置，内容起，内容终)；
* vector.end(); vector.begin()
* 二叉树的先中后序遍历，递归（直接调用递归时间复杂度和语言有关【结果相加的时候】；
* 可以采用定义全局变量+外部辅助函数
* 注意返回值


```
3.17ImplementStackusingQueues(225)
```
* 用多于一个辅助队列来进行颠倒，直接把原队列翻转成栈
* 注意队列的基本操作 q.front(), q.pop(), p.push(),q.empty();
* 队列是先进先出，队尾进队头出；

```
3.18ImplementQueueusingStacks(232)
```
* 和225类似。不同的是队列可以通过取出再重新放回而实现颠倒，但是栈取出放回是一致的，所以只能用2个栈来实现队列。


```
3.NextGreaterElement(496)
```