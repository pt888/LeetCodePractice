class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int start = digits.size()-1;
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for(auto &i : digits){
            int temp = i + carry;
            i = temp%10;
            carry = temp/10;
            if(carry == 0) break;
        }
        if(carry > 0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};