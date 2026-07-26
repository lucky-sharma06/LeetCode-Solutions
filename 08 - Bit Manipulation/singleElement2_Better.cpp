#include<iostream>
using namespace std;
int findSingleElement(int arr[], int n){
    int idx = 0;
    int ans = 0;
    // idx -> 0 - 31 (for int);
    for(idx = 0; idx <= 31; idx++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] & (1 << idx)){
                // means bit set hai
                cnt++;
            }
        }
        if(cnt % 3 == 1){
            // set the idx bit
            ans = ans | (1 << idx);
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // array is set 
    cout << findSingleElement(arr, n) << endl;
    return 0;
}