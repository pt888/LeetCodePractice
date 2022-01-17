// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    int maxsum=INT_MIN;
	    int sum=0;
	    bool neg=false;
	    int start=0;
	    int finalStart=-1;
	    bool pos=false;
	    int finalEnd=-1;
	    for(int i=0;i<n;i++){
	        if(a[i]<0){
	            neg=true;
	            if(maxsum<sum){
	                maxsum=sum;
	                finalStart=start;
	                finalEnd=i-1;
	            }
	            sum=0;
	        }
	        else{
	            pos=true;
	            if(neg==true){
	                start=i;
	                neg=false;
	            }
	          //  cout<<"start:"<<start<<endl;
	           sum+=a[i];
	        }
	        //cout<<"sum:"<<sum<<endl;
	    }
	    if(maxsum<sum){
	       finalStart=start;
	       finalEnd=n-1;
	   }
	   //cout<<finalStart<<" "<<finalEnd<<endl;
	    vector<int> res;
	    if(!pos) return (vector<int>{-1});
	    for(int i=finalStart;i<=finalEnd;i++){
	        res.push_back(a[i]);
	    }
	    return res;
	}
};

// { Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends