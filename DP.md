# 常见DP问题

## 最小路径和（64）
* 递归思路，迭代思路
* 数组相关dp 只用找出dp[i][j] 与之相关的状态
* dp函数或者数组的定义： 从左上角位置 (0, 0) 走到位置 (i, j) 的最小路径和为 dp(grid, i, j)。
* 注意初始化（递归是在dp函数中处理； 迭代是初始之后开始迭代）


## 魔塔（174）
* 递归思路，迭代思路
* dp函数的定义或者数组的定义：从 grid[i][j] 到达终点（右下角）所需的最少生命值是 dp(grid, i, j)。
* 注意判别递推状态 只能从dp[i][j+1]和dp[i+1][j] 推出dp[i][j] （右下往左上推）
* 而不能从dp[i-1][j] 和dp[i][j-1]推出 dp[i][j]（因为只知道左上角到达所需要的最小生命值，但是不知道到达时候的生命值）


## 自由之路（514）
* 明确状态：轮盘指针的位置和需要输入的字符
* 选择：往左还是往右拨动；
* dp数组（函数）定义：从转盘第i个字母拨到key中第j个字母之后所需要的最小操作；（通常数组需要+1处理越界，dp函数贼直接越界后的边界判定即可）
* 轮盘可以逆时针，顺时针->需要考虑后续字符的操作大小， 状态转移时当拨到以后，剩余元素所需要的操作
* 当ring中有重复元素时，需要整体考虑，也就是递归入口变成拨到元素的索引；


## 打家劫舍（198 213 337）
* 198：1. 明确状态和选择： 房子是状态，抢不抢是选择；抢：nums[i] + dp[i+2]; 不抢： dp[i+1]
* 213: 有开始和结束的DP函数
* 