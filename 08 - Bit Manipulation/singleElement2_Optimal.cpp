#include<iostream>
#include<algorithm>
using namespace std;
int findSingleElement(int arr[], int n){
    // this is the optimal approach
    sort(arr, arr + n);
    int i = 1;
    for(i = 1; i < n; i += 3){
        if(arr[i - 1] != arr[i]){
            // mismatch and i-1 index is the ans
            return arr[i - 1];
        }
    }
    // ab tab mismatch ni mila 
    if(n % 3 != 0){
        return arr[n - 1];
    }
    
    // no single element
    return 0;
    
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