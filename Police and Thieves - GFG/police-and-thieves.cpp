// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        int count=0;
        for(int i=0;i<n;i++){
            int start=-1;
            int found=false;
            int end=-1;
            if(arr[i]=='P'){
                start=max(0,i-k);
                end=min(i+k,n);
               // cout<<start<<" "<<end<<endl;
                for(int i=start;i<=end;i++){
                    if(arr[i]=='T' && !found){
                        count++;
                        arr[i]='I';
                        found=true;
                    
                    }
                }
            }
        }
        //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
       // cout<<endl;
        return count;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends