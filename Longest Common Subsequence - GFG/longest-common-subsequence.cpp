// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> lls(x,vector<int>(y));
        if(s1[0]==s2[0]) lls[0][0]=1;
        else lls[0][0]=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(s1[i]==s2[j]){
                    if(i==0) lls[i][j]=1;
                    else if(j==0) lls[i][j]=1;
                    else lls[i][j]=lls[i-1][j-1]+1;
                }
                else {
                    if(i==0) lls[i][j]=lls[i][j-1];
                    else if(j==0) lls[i][j]=lls[i-1][j];
                    else lls[i][j]=max(lls[i-1][j],lls[i][j-1]);
                }
            }
        }
        return lls[x-1][y-1];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends