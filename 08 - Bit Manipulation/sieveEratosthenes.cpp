#include<iostream>
using namespace std;
int main(){
    int n; 
    cin >> n;

    int prime[n + 1];
    // mark all as 1 (prime)
    for(int i = 2; i <= n; i++){
        prime[i] = 1;
    }

    for(int i = 2; i*i <= n; i++){
        if(prime[i] == 1){
            for(int j = i*i; j <= n; j += i){
                prime[j] = 0;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            cout << i << " "; 
        }
    }
    cout << endl;
    return 0;
}