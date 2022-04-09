class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> rotten;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) rotten.push({i,j});
                
            }
        }
        int minutes=0;
        while(!rotten.empty()){
            int s=rotten.size();
           // cout<<s<<endl;
            for(int i=0;i<s;i++){
                auto p=rotten.front();
                rotten.pop();
                int x=p.first;
                int y=p.second;
                //cout<<x<<","<<y<<endl;
                grid[x][y]=2;
                if(x-1 >=0 && grid[x-1][y]==1) rotten.push({x-1,y}),grid[x-1][y]=2;
                if(x+1 <m && grid[x+1][y]==1) rotten.push({x+1,y}),grid[x+1][y]=2;
                if(y-1 >=0 && grid[x][y-1]==1) rotten.push({x,y-1}),grid[x][y-1]=2;
                if(y+1 <n && grid[x][y+1]==1) rotten.push({x,y+1}),grid[x][y+1]=2;; 
            }
            minutes++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
                
            }
        }
        return minutes==0?0:minutes-1;
    }
};