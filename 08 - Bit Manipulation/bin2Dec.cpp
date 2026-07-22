#include<iostream>
#include<cmath>
using namespace std;
int bin2Dec(string& binary){
    // traverse from back
    int n = binary.size();
    int cnt = 0;
    int dec = 0;
    for(int i = n - 1; i >= 0; i--){
        if(binary[i] == '1'){
            dec += pow(2, cnt);
        }
        cnt++;
    }
    return dec;
}
int main(){
    string binary;
    cin >> binary;
    cout << bin2Dec(binary) << endl;
    return 0;
}