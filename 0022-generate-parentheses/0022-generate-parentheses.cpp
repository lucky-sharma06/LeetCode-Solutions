class Solution {
public:
    void genPar(int open, int close, int n, vector<string>& ans, string& ds){
        // Base Case:
        if((open == n) && (close == n)){
            ans.push_back(ds);
            return;
        }

        if(open < n){
            // opening
            ds.push_back('(');
            genPar(open + 1, close, n, ans, ds);
            ds.pop_back();
        }
        if(open > close){
            ds.push_back(')');
            genPar(open, close + 1, n, ans, ds);
            ds.pop_back();
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;

        genPar(0, 0, n, ans, ds);
        return ans;
    }
};