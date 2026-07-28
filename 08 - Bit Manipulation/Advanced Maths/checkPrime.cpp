#include<iostream>
using namespace std;
int main(){
    int n; 
    cin >> n;
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cnt++; // n is divisible by i
            if(n/i != i){
                cnt++; // n/i can also divide n
            }
        }
    }
    if(cnt == 2){
        cout << "Prime" << endl;
    }
    else{
        cout << "Not Prime" << endl;
    }
    return 0;
}