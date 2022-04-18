class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        stack<int> st;
        st.push(prices[0]);
        for(int i=1;i<n;i++){
            int te=st.top();
            if(te>prices[i]){
                st.pop();
                st.push(prices[i]);
            }
            else{
                int temp=prices[i]-st.top();
                profit=max(profit,temp);
            }
        }
        return profit;
    }
};