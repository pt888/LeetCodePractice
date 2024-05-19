class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candiesLeft(n, 1);
        vector<int> candiesRight(n, 1);
        for(int i =1; i < n; i++){
            if(ratings[i] > ratings[i-1]) candiesLeft[i] = candiesLeft[i-1]+1;
        }
        for(int i =n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) candiesRight[i] = candiesRight[i+1]+1 ;
        }
        int count = 0;
        for(int i =0; i <n; i++){
           count += max(candiesLeft[i], candiesRight[i]); 
        }
        return count;
    }
};