
class Solution {
public:
    map<string, vector<string>> preMap;
 
    void util(vector<string>& words, vector<vector<string>> &ans, vector<string> &temp){
        if(words[0].size() == temp.size()){
            ans.push_back(temp);
            return;
        }

        int n = temp.size();
        string pre = "";
        for(auto t : temp){
            pre += t[n];
        }
        for(auto word: preMap[pre])
        {
            temp.push_back(word);
            util(words, ans, temp);
            temp.pop_back();
        }  
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        preMap.clear();
        for(auto w : words){
            for(int i = 0; i <= w.size();i++){
                preMap[w.substr(0, i)].push_back(w);
            }
        }
        vector<string> temp;
        util(words, ans, temp);
        return ans;
    }
};