#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int lowerBound = n; 
    int low = 0;
    int high = n - 1;
    int x;
    cin >> x;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= x){
            high = mid - 1;
            lowerBound = mid;
        }
        else{
            low = mid + 1;
        }
    }

    cout << "The lower bound is: " << lowerBound << endl;
    return 0;
}