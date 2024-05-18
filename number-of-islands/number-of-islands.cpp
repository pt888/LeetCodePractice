class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == true) return;
        visited[i][j] = true;

        if(i-1 >= 0 && grid[i-1][j]=='1') dfs(grid, i-1, j, visited);
        if(i+1 < n && grid[i+1][j]=='1') dfs(grid, i+1, j, visited);
        if(j-1 >= 0 && grid[i][j-1]=='1') dfs(grid, i, j-1, visited);
        if(j+1 < m && grid[i][j+1]=='1') dfs(grid, i, j+1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int island = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    island++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return island;
    }
};