class Solution {
public:
    string minWindow(string s, string t) {
        int end = s.size();
        map<char, int> mp;
        for(auto i : t){
            mp[i]++;
        }
        int windowStart = 0;
        int windowEnd = 0;
        int lengthOfTLeft = t.size();
        int minStart = 0;
        int minLength = INT_MAX;
        while(windowEnd < end){
            if(mp[s[windowEnd]] > 0) lengthOfTLeft--;
            mp[s[windowEnd]]--;   
            windowEnd++;
            while(lengthOfTLeft == 0){
                if(windowEnd - windowStart < minLength ){
                    minLength = windowEnd-windowStart;
                    minStart = windowStart;
                }
                mp[s[windowStart]]++;
                if(mp[s[windowStart]] > 0) lengthOfTLeft++;
                windowStart++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);   
    }
};