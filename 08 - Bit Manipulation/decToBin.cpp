#include<iostream>
#include<algorithm>
using namespace std;

string convert2string(int n){
    string ans;
    if(n == 0) return "0";

    while(n > 0){
        if(n % 2 == 1){
            ans.push_back('1');
        }
        else{
            ans.push_back('0');
        }
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;
    string ans = convert2string(n);
    cout << ans << endl;
    return 0;
}
