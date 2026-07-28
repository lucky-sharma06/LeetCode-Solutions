#include<iostream>
#include<vector>
using namespace std; 
int main(){
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n != 1) ans.push_back(n); // or if(n > 1) anything will work here
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;

}