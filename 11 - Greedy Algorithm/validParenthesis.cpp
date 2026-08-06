#include<iostream>
using namespace std;
bool validPar(string s, int idx, int cnt){
    if(cnt < 0) return false;
    if(idx == s.length()) return cnt==0;

    if(s[idx] == '('){
        return validPar(s, idx + 1, cnt + 1);
    }
    if(s[idx] == ')'){
        return validPar(s, idx + 1, cnt - 1);
    }

    // if the s[idx] is *(astericks)
    return validPar(s, idx + 1, cnt + 1) || validPar(s, idx + 1, cnt - 1) || validPar(s, idx + 1, cnt);
    // Tc = O(3^N) Sc = O(3N) -> stack spae
}
int main(){
    cout << validPar("*))", 0, 0) << endl;
    return 0;
}