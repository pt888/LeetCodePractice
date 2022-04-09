class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int oldColor){
        int m=image.size();
        int n=image[0].size();
        //cout<<sr<<":"<<sc<<endl;
        if(image[sr][sc]==newColor) return;
        image[sr][sc]=newColor;
        //cout<<"color"<<image[sr][sc]<<endl;
        if(sr-1>=0 && image[sr-1][sc]==oldColor) dfs(image,sr-1,sc,newColor,oldColor);
        if(sr+1<m && image[sr+1][sc]==oldColor) dfs(image,sr+1,sc,newColor,oldColor);
        if(sc-1>=0 && image[sr][sc-1]==oldColor) dfs(image,sr,sc-1,newColor,oldColor);
        if(sc+1<n && image[sr][sc+1]==oldColor) dfs(image,sr,sc+1,newColor,oldColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int oldColor=image[sr][sc];
       dfs(image,sr,sc,newColor,oldColor);
       return image;
    }
};