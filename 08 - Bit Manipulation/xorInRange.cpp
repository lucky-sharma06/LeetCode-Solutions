#include<iostream>
using namespace std;

int xor1_N(int n){
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0;
}
int main(){
    int L = 4;
    int R = 7;
    // xor of element from L to R is 
    // 1-L ^ 1-R
    int ans = xor1_N(L - 1) ^ xor1_N(R);
    cout << ans << endl;
    return 0;
}