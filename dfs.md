##  1.矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
（**记忆化dfs，同一个单元格对应的最长递增路径的长度是固定不变的**，需要比较下一次前进方向的大小，所以用for遍历四个方向）

```
class Solution {
public:
    int m, n;
    static constexpr int dirs[4][2] = {-1, 0}, {1, 0}, {0, -1}, {0, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return 0;
        n = matrix[0].size();
        if(n == 0) return 0;
        auto memo = vector<vector<int>> (m, vector<int>(n));
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, dfs(matrix,i,j,memo));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int i , int j, vector< vector<int> > & memo){
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        ++memo[i][j];
        for(int k=0;k<4;k++){
            int new_i = i+dirs[k][0], new_j = j+dirs[k][1];
            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && matrix[new_i][new_j] > matrix[i][j]){
                memo[i][j] = max(memo[i][j],dfs(matrix,new_i,new_j,memo)+1);
            }
        }
        return memo[i][j];
    }

};
```

### 417. 太平洋大西洋水流问题
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋。
(思路：**从边界往上dfs，用两个二维数组分别记录最远能到的位置，之后都满足则添加结果**)
```
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{ {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 0 || heights[0].size() == 0){
            return {};
        }
        m = heights.size(), n = heights[0].size();
        auto pacific = vector<vector<bool>> (m,vector<bool>(n));
        auto atlantic = vector<vector<bool>> (m,vector<bool>(n));
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific,heights);
        }
        for (int j = 1; j < n; j++) {
            dfs(0, j, pacific,heights);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, atlantic,heights);
        }
        for (int j = 0; j < n - 1; j++) {
            dfs(m - 1, j, atlantic,heights);
        }     
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<bool>>& memo, vector<vector<int>>& heights){
        if(memo[i][j]) return;
        memo[i][j] = true;
        for(int k=0;k<4;k++){
            int new_i = i+dirs[k][0], new_j = j+dirs[k][1];
            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && heights[new_i][new_j] >= heights[i][j]){
                dfs(new_i,new_j,memo,heights);
            }
        }
    }
};
```