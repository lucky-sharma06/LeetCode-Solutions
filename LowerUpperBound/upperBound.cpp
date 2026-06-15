#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int upperBound = n; 
    int low = 0;
    int high = n - 1;
    int x;
    cin >> x;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] > x){
            high = mid - 1;
            upperBound = mid;
        }
        else{
            low = mid + 1;
        }
    }

    cout << "The upper bound is: " << upperBound << endl;
    return 0;
}