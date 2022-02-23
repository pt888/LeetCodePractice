class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //vector<vector<int>> ans(n)
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                {
                    ans.push_back({i,j});
                }
            }
        }
        for(auto i:ans){
            cout<<i.first<<" "<<i.second<<endl;
            for(int j=0;j<m;j++){
                matrix[i.first][j]=0;
            }
             for(int j=0;j<n;j++){
                matrix[j][i.second]=0;
            }
        }
        
    }
};