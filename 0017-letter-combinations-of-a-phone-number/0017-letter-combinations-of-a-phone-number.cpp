class Solution {
public:
    void letterCombo(int idx, string letters[], string digits, vector<string>& ans, string& ds){
        // Base Case
        if(idx == digits.size()){
            ans.push_back(ds);
            return;
        }
        int digit = digits[idx] - '0';
        for(const char& ch : letters[digit]){
            ds.push_back(ch);
            letterCombo(idx + 1, letters, digits, ans, ds);
            ds.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string ds;

        letterCombo(0, letters, digits, ans, ds);
        return ans;
    }
};