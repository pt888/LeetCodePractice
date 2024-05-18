class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        int start = 0;
        int end = 0;
        int n = s.size();
        map<char, int> mp;
        int ans = -1;
        while(end < n){
            if(mp[s[end]] == 0){
                mp[s[end]]++;
            }
            else{
                ans = max(ans, end-start);
                while(s[start] != s[end]) {
                    mp[s[start]]--;
                    start++;
                } 
                start++;  
            }
            end++;
            ans = max(ans, end-start);
        }
        return ans;
    }
};