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


## 5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
（思路：用一个辅助函数往两端找回文串，返回最长的）
```
class Solution {
public:
    string res = "";
    string longestPalindrome(string s){
        int n = s.size();
        if(n<2) return s;
        for(int i=0;i<n;i++){
            string s1 = check(s,i,i);
            string s2 = check(s,i,i+1);
            res = res.size()>s1.size()?res:s1;
            res = res.size()>s2.size()?res:s2;
        }
        
        return res;
    }
    string check(string s, int l,int r){
        while(l>=0 && r<s.size() && s[l] ==  s[r] ){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
};
```

动态规划：dp[i][j]表示从i到j是否为回文串，**遍历过程：for(i:len)for(i:n)**
```
class Solution {
public:
    string res = "";
    string longestPalindrome(string s){
        int n = s.size();
        if(n<2) return s;
        vector<vector<bool>> dp(n,vector<bool>(n));
        int maxlen = 1;
        int begin;
        for(int i=0; i<n;i++){
            dp[i][i] = true;
        }
        for(int L=2;L<=n;L++){
            for(int i=0;i<n;i++){
                int j = i+L-1;
                if(j>=n){
                    break;
                }
                if(s[i] != s[j]){
                    dp[i][j]=false;
                }else{
                    if(j-i<3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
        if(dp[i][j] && j-i+1>maxlen){
            maxlen = j-i+1;
            begin = i;
        }
        }
        }
    return s.substr(begin,maxlen);
    }
};
```


## 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串
```
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2]; //p[j-2]!=s[i-1]x*匹配0次
                    if (matches(i, j - 1)) { //p[j-2]==s[i-1]
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
```

## 542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
(思路：常规bfs)
```
class Solution {
public:
    int dir[4][2]={0, 1, 1, 0, -1, 0, 0, -1};
    vector<vector<bool>> visited;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        visited.resize(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int cnt = 1;
        while(!q.empty()){
            int sz = q.size();
            cout << sz << endl;
            for(int k=0;k<sz;k++){
                auto [i,j] = q.front();
                q.pop();
                visited[i][j] = true;
                for(int c=0;c<4;c++){
                    int x = i+dir[c][0], y=j+dir[c][1];
                    if(x<0||x>=m||y<0||y>=n||visited[x][y]==true||mat[x][y]==0) continue;
                    mat[x][y] = cnt;
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }
            cnt++;
        }
        return mat;
    }
};
```

## 741. 摘樱桃
给你一个 n x n 的网格 grid ，代表一块樱桃地，每个格子由以下三种数字的一种来表示：
0 表示这个格子是空的，所以你可以穿过它。
1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
-1 表示这个格子里有荆棘，挡着你的路。
请你统计并返回：在遵守下列规则的情况下，能摘到的最多樱桃数：
从位置 (0, 0) 出发，最后到达 (n - 1, n - 1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为 0 或者 1 的格子）；
当到达 (n - 1, n - 1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为 0 ）；
如果在 (0, 0) 和 (n - 1, n - 1) 之间不存在一条可经过的路径，则无法摘到任何一个樱桃。
(思路：**等价于两个人同时从起点走，都能走到右下时候能摘樱桃的个数，同一个位置只能摘一次**)
dp[k][x1][x2]:**定义为走了k步，x1在x1行，x2在x2行，根据k步可以计算出对应的列**
```
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = 55;
        int dp[2*N][N][N];
        for(int k=0;k<=2*n;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    dp[k][i][j] = INT_MIN;
                }
            }
        }
        dp[2][1][1] = grid[0][0];
        for(int k=3;k<=2*n;k++){
            for(int i1=1;i1<=n;i1++){
                for(int i2=1;i2<=n;i2++){
                    int j1=k-i1, j2=k-i2;
                    if(j1<=0 || j1>n || j2<=0 || j2>n) continue;
                    int A = grid[i1-1][j1-1], B = grid[i2-1][j2-1];
                    if(A==-1 || B==-1) continue;
                    int a = dp[k-1][i1-1][i2],b=dp[k-1][i1][i2],c =dp[k-1][i1][i2-1],d=dp[k-1][i1-1][i2-1];
                    int t = max(max(a,b),max(c,d)) + A;
                    if(i1!=i2) t+= B;
                    dp[k][i1][i2] = t;
                }
            }
        }
        return dp[2*n][n][n] <=0 ?0:dp[2*n][n][n];
        
    }
};
```