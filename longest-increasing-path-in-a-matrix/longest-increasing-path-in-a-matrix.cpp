class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,1},{0,-1}};

    bool isValid(int x, int y, int n, int m){
        return (x>=0 && x<n && y>=0 && y<m);
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dist){
        int n = matrix.size();
        int m = matrix[0].size();

        if(dist[i][j]!=0) return dist[i][j];

        int ans = INT_MIN;
        for(auto d : dir){
            int x = d.first + i;
            int y = d.second + j;
            if(isValid(x, y, n, m) && matrix[x][y] > matrix[i][j]) 
                ans = max(ans, dfs(matrix, x, y, dist));
        }
        return dist[i][j] = max(dist[i][j], ans)+1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix, i, j, dist));
            }
        }    
        return ans;
    }
};