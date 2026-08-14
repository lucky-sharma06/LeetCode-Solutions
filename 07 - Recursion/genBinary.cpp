#include<iostream>
#include<vector>
using namespace std;
void genBinary(int idx, int n, vector<string>& ans, string& ds){
    // Base case
    if(idx == n){
        ans.push_back(ds);
        return;
    }
    ds.push_back('0');
    genBinary(idx + 1, n, ans, ds);
    ds.pop_back();
    ds.push_back('1');
    genBinary(idx + 1, n, ans, ds);
    ds.pop_back();

}
int main(){
    vector<string> ans;
    string ds;

    int n = 4;
    genBinary(0, n, ans, ds);

    for(auto bin : ans){
        cout << bin << " ";
    }
    cout << "\n";
    return 0;
}