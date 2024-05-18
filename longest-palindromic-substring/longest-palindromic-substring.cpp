class Solution {
public:

    pair<int,int> palindromeLength(string s, int left, int right){
        while(left >= 0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return {left, right};
    }

    string longestPalindrome(string s) {
        int n = s.size();
        
        int ansStart = 0;
        int ansLen = 0;

        for(int i = 0 ;i < n; i++){
            auto op = palindromeLength(s, i, i);
            
            auto ep = make_pair(0,0);
            if(i-1 >= 0 && s[i-1] == s[i])
                ep = palindromeLength(s, i-1, i);

            int l1 = op.second - op.first - 1;
            int l2 = ep.second - ep.first - 1;

            if(ansLen < max(l1,l2)){
                ansLen = max(l1,l2);
                ansStart = l1 > l2? op.first+1:ep.first+1;
            }
        }
        return s.substr(ansStart, ansLen);
    }
};