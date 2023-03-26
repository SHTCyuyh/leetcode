# Array(数组)

vector.resize(n) 当resize n大于原来vector的长度时，末尾补0；当n小于时则截取到前n个
快慢指针： 1.原地修改数组；2.滑动窗口
左右指针：1.二分查找；2.两数之和；3、反转数组4、回文串判断
![avatar](fig/二分查找.png)
```
3.22 moveZeroes(283) + removeElement(27)
```
* 快慢指针，因为需要保留原始相对顺序，不能从两端向中间逼近，只能用快慢从前往后遍历
* 为什么返回数值是整数，但输出的答案是数组
请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

```
3.22 twoSum(167) +reverseString(344)
```
* 左右指针的终止条件，左指针 小于右指针


```
3.22 longestPalindrome（5）
```
* 回文串判定：1.两边往中间走，相等；2.从中心往两边走
* 字符长度判定 s.length(), 切割字符string s s.substr(begin, lenth);
* string类是一个保存字符的动态数组，由于其中有一个接口c_str,转化成c语言的字符串，要以\0结尾，所以string类最后会有一个\0.
* vector<T>是一个保存T类型的动态数组，vector<char>也是保存字符的动态数组，但是，不会以\0结尾，不保存\0.


```
3.22Range Sum Query - Immutable 前缀和
```
* 前缀和主要适用的场景是原始数组不会被修改的情况下，频繁查询某个区间的累加和
* sumRange 函数仅仅需要做一次减法运算，避免了每次进行 for 循环调用，最坏时间复杂度为常数 O(1)
* 矩阵
* ![avatar](fig/前缀和矩阵.png)

```
3.22 差分数组(1109)
```
* 差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减。
* ![avatar](fig/差分数组.png)
* 差分数组类构造函数，初始化全0， increment(i,j,val),  result();
* 注意increment中边界条件，只用修改diff[i] 和 diff[j+1] 如果j+1越界，则不用修改
* for (auto &booking: bookings)写法
* 熟悉一下c++类的构造；


```
3.25 旋转图像(48)
```
* 顺时针旋转图像90：按照左上到右下的对角线进行镜像对称 然后再对矩阵的每一行进行反转：
* 逆时针旋转图像90：按照右上到左下的对角线进行镜像对称 然后再对矩阵的每一行进行反转


```
3.26spiralOrder(54 & 59)
```
* ![avatar](fig/3.26spiralOrder.png)
* ![avatar](fig/3.26spiralOrder.png)


```
3.26滑动窗口(76)
```
* 滑动窗口基本思路：增大窗口，从右加入元素；不满足条件，从左缩小窗口
* ![avatar](fig/3.26滑动窗口.png)

```
3.26minWindow(76) & checkInclusion(567) findAnagrams（438）
```
* window 和need 之间的关系，可以用一个valid数来记录满足的个数 
* right++ 的时候， window对应++， 判断need ==  window时 valid++
* 缩小窗口时，先判断need == window的情况，valid--后再window--；
* vector<int> res; 动态往数组中加元素， res.push_back() 