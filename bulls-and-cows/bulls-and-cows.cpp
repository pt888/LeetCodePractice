class Solution {
public:
    string getHint(string secret, string guess) {
        int cows = 0;
        int bulls = 0;
        map<char, int> sec;
        for(int i =0; i <secret.size();i++){
            if(secret[i] == guess[i]) bulls++;
            else {
                if(sec[secret[i]] < 0) cows++;
                sec[secret[i]]++;
                if(sec[guess[i]] > 0) cows++;
                sec[guess[i]]--;
                
            }       
        }
        return to_string(bulls) + 'A' + to_string(cows)+ 'B';
    }
};