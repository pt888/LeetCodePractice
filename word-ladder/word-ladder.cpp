class Solution {
public:
    bool isDifferingByOneCharacter(string a, string b){
        int diff = 0;
        for(int i = 0 ; i < a.size(); i++){
            if(a[i] != b[i]) diff++;
        }
        return diff==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) ==  wordList.end()) return 0;
        map<string, vector<string>> mp;
        if(find(wordList.begin(), wordList.end(), beginWord) ==  wordList.end()) 
            wordList.push_back(beginWord);
        map<string, bool> visited;

        for(int i = 0; i <wordList.size(); i++){
            for(int j = 0; j <wordList.size(); j++){
                if(i != j && isDifferingByOneCharacter(wordList[i], wordList[j])) mp[wordList[i]].push_back(wordList[j]);
            }
        }
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;
        while(!q.empty()){
            ans++;
            int s = q.size();
            for(int i = 0; i <s; i++){ 
                string temp = q.front();
                q.pop();
                vector<string> t = mp[temp];
                for(int j = 0; j < t.size(); j++) {
                    if(t[j] == endWord) {
                        return ans;
                    }
                    if(visited[t[j]] == false) q.push(t[j]);
                    visited[t[j]] = true;
                }
            }
        }
        return 0;
    }
};