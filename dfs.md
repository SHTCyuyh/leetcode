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

### 419. 甲板上的战舰
给你一个大小为 m x n 的矩阵 board 表示甲板，其中，每个单元格可以是一艘战舰 'X' 或者是一个空位 '.' ，返回在甲板 board 上放置的 战舰 的数量。战舰 只能水平或者垂直放置在 board 上。换句话说，战舰只能按 1 x k（1 行，k 列）或 k x 1（k 行，1 列）的形状建造，其中 k 可以是任意大小。两艘战舰之间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。
(思路：翻译，检查所有横着和列是否是相同的'X',计数)
```
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()== 0){
            return 0;
        }
        int cnt = 0;
        m = board.size(), n = board[0].size();
        visited.resize(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X'){
                    dfs(board,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& board,int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='X') return;
        board[i][j] = '.';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
};
```

### 463. 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
```
class Solution {
public:
    int m, n;
    int res;
    vector<vector<int>> dirs{ {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        res = 0;
        for(int i=0; i<m;i++){
            for(int j=0;j<n; j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    for(int k=0;k<4;k++){
                        int x = i+dirs[k][0];
                        int y = j+dirs[k][1];
                        if(x<0||x>=m||y<0||y>=n|| grid[x][y]==0){
                            cnt += 1
                        }
                    }

                    res += cnt;
                }
            }
        }
        return res;
    }
};
```

### 529. 扫雷游戏
给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
'M' 代表一个 未挖出的 地雷，
'E' 代表一个 未挖出的 空方块，
'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
'X' 则表示一个 已挖出的 地雷。
(思路：遇到数字就结束，如果每次都是'E',则递归的搜索下一个E)
```
class Solution {
public:
    vector<vector<int>> dirs{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int r = click[0], c = click[1];
        if(board[r][c] == 'M' || board[r][c] == 'X'){
            board[r][c] = 'X';
            return board;
        }
        int num = 0;
        for(int i=0;i<8;i++){
            int x = r+dirs[i][0], y = c+dirs[i][1];
            if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='M')num++;
        }
            if(num >0){
                board[r][c] = '0'+num;
                return board;
            }
        board[r][c] = 'B';
        for(int i=0;i<8;i++){
            int x = r+dirs[i][0], y = c+dirs[i][1];
            if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='E'){
                vector<int> next_click = {x, y};
                updateBoard(board, next_click);
                }
            }
    return board;
    }
};
```

### 695. 岛屿的最大面积
给你一个大小为 m x n 的二进制矩阵 grid 。
岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
岛屿的面积是岛上值为 1 的单元格的数目。
计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
(思路：带返回值的dfs，用for循环遍历方向，之后dfs递归调用)
```
class Solution {
public:
    int m,n;
    vector<vector<int>> dirs{-1,0},{1,0},{0,1},{0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, dfs(grid,i,j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 ||j>=n || grid[i][j]==0) return 0;
        grid[i][j] = 0;
        int ans = 1;
        for(int k=0;k<4;k++){
            int x = i+dirs[k][0], y=j+dirs[k][1];
            ans += dfs(grid,x,y);
        }
        return ans;
    }
};
```

### 733. 图像渲染
有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。
你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。
为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。
(思路：思考什么时候的返回值是void，什么时候的返回值是int或者是别的特殊返回值，**计算单个连通块的返回值**)
```
class Solution {
public:
    int m,n;
    vector<vector<int>> dirs{-1,0},{1,0},{0,1},{0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.size()==0 || image[0].size()==0) return {};
        m = image.size(), n = image[0].size();
        int flag = image[sr][sc];
        if(flag != color){
            dfs(image,sr,sc,flag,color);
        }
        return image;
    }
    void dfs(vector<vector<int>>& image, int x, int y, int flag,int color){
        if (image[x][y] == flag) {
            image[x][y] = color;
            for (int i = 0; i < 4; i++) {
                int mx = x + dirs[i][0], my = y + dirs[i][1];
                if (mx >= 0 && mx < m && my >= 0 && my <n) {
                    dfs(image, mx, my, flag, color);
                }
            }
        }
    }
};
```
### 并查集
基础结构
```
class UF {

private:
    int count;
    int* parent;
    // 新增一个数组记录树的“重量”
    int* size;

public: 
    UF(int n) {
        this->count = n;
        parent = new int[n];
        // 最初每棵树只有一个节点
        // 重量应该初始化 1
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    /* 将 p 和 q 连接 */
    void union(int p, int q) {
        int rotP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        // 将两棵树合并为一棵
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }
    /* 判断 p 和 q 是否连通 */
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    /* 返回图中有多少个连通分量 */
    int count();
};
```

### 778. 水位上升的泳池中游泳
在一个 n x n 的整数矩阵 grid 中，每一个方格的值 grid[i][j] 表示位置 (i, j) 的平台高度。
当开始下雨时，在时间为 t 时，水池中的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
你从坐标方格的左上平台 (0，0) 出发。返回 你到达坐标方格的右下平台 (n-1, n-1) 所需的最少时间 。
（grid中的值无重复，且属于0-n*n）
```
class Solution {
public:
    int n;
    int find(vector<int>&f, int x){
        if(f[x]!=x){
            f[x] = find(f,f[x]);
        }
        return f[x];
    }
    void merge(vector<int>& f, int x, int y){
        int fx = find(f,x), fy=find(f,y);
        f[fx] = fy;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n*n);
        //查并集初始化
        for(int i=0;i<n*n;i++){
            f[i] = i;
        }
        vector<pair<int,int>> idx(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                idx[grid[i][j]] = make_pair(i,j);
            }
        }
        vector<pair<int, int>> directions{0,1},{0,-1},{1,0},{-1,0};
        for(int threshold=0;threshold<n*n;threshold++){
            auto [i,j] = idx[threshold];
            for(const auto [di,dj]:directions){
                int ni=i+di,nj=j+dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] <= threshold){
                    merge(f,i*n+j,ni*n+nj);
                }
            }
            if(find(f,0) == find(f,n*n-1)){
                return threshold;
            }
        }
    return -1; 
    }
};
```

## 827. 最大人工岛
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
返回执行此操作后，grid 中最大的岛屿面积是多少？
岛屿 由一组上、下、左、右四个方向相连的 1 形成。
**dfs(g,i,j,mark) 将连通块标记为mark，并且计数**
```
class Solution {
public:
    int count;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void dfs(vector<vector<int>>& grid, int i, int j, int mark){
        if(grid[i][j] != 1 || grid[i][j]==0) return;
        count++;
        grid[i][j] = mark;
        for(int k=0;k<4;k++){
            int nx = i+dir[k][0], ny = j+dir[k][1];
            if(nx < 0 || nx >= grid.size() || ny<0 || ny >= grid[0].size()) continue;
            dfs(grid,nx,ny,mark);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = gird.size(), m=grid[0].size();
        unordered_map<int,int> gridNum;
        int mark = 2;
        bool isfull = true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) isfull=false;
                if(grid[i][j] == 1){
                    count = 0;
                    dfs(grid,i,j,mark);
                    gridNum[mark] = count;
                    mark++;
                }
                
            }
        }
        if(isfull) return n*m;
        int res =0;
        unordered_set<int> visited;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count = 1;
                    visited.clear();
                    for(int k=0; k<4;k++){
                        int neari = i + dir[k][1]; // 计算相邻坐标
                        int nearj = j + dir[k][0];
                        if (neari < 0 || neari >= grid.size() || nearj < 0 || nearj >= grid[0].size()) continue;
                        if(visitedGrid.count(grid[neari][nearj])) continue;
                        count += gridNum[grid[neari][nearj]];
                        visitedGrid.insert(grid[neari][nearj]);
                    }
                }
            }
        }
    }
}；
```

