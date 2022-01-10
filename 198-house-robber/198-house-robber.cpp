class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        //int dp[]=new int[n];
        vector<int> dp(n);
        dp[0]=nums[0];
        if(n>1)
            dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<n;i++){
                dp[i]=max((nums[i]+dp[i-2]),dp[i-1]);
        }
        return dp[n-1];
    }
};