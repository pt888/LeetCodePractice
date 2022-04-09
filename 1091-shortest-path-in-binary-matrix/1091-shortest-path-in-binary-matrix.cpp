class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> path;
        int pathLength=0;
        if(grid[0][0]==0){
            if(n==1) return 1;
            path.push({0,0});}
        while(!path.empty()){
            int s=path.size();
            pathLength++;
           // cout<<s<<endl;
            for(int i=0;i<s;i++){
                auto p=path.front();
                path.pop();
                int x=p.first;
                int y=p.second;
                //cout<<x<<","<<y<<endl;
                grid[x][y]=1;
                for(int i=x-1;i<=x+1;i++){
                    for(int j=y-1;j<=y+1;j++){
                        //cout<<i<<" :"<<j<<endl;
                        if(i==n-1 && j==n-1 && grid[i][j]==0) return pathLength+1;
                        if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==0) path.push({i,j}),grid[i][j]=1;   
                    }
                }
            }
            
        }
        return -1;
    }
};



