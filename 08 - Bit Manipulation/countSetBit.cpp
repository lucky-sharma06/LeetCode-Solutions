#include<iostream>
using namespace std;
int main(){
    int n = 13;
    int cnt = 0;
    int temp = n;
    // while(temp > 0){
    //     if(temp % 2 == 1){
    //         cnt++;
    //     }
    //     temp /= 2;
    // }
    while(temp > 0){
        cnt += temp & 1;
        temp >>= 1; // or temp = temp >> 1; it is equivalent to temp / 2(ki power 1);
    }

    // while(temp > 0){
    //     temp = temp & (temp - 1);
    //     cnt++;
    // }    this is also a method to count 
    // O(logn)

    cout << cnt << endl;
    
}