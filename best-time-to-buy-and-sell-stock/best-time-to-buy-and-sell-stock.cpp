class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minP = INT_MAX;
        int maxP = 0;
        for(int i = 0; i < n ; i++){
            if(prices[i] < minP) minP= prices[i];
            else{ maxP = max(maxP, prices[i] - minP);}

        }
        return maxP;
    }
};