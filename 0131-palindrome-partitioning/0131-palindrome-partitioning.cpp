class Solution {
public:
    bool isPalindrome(string s, int st, int end) {
        while (st <= end) {
            if (s[st++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void helper(int idx, string& s, vector<string>& path, vector<vector<string>>& res) {
        if(idx == s.size()){
            // partition at the end;
            res.push_back(path);
            return;
        }
        // s.substr(idx, length);
        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                // if is is the palindrome then accept
                path.push_back(s.substr(idx, i - idx + 1));
                helper(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        helper(0, s, path, res);
        return res;
    }
};