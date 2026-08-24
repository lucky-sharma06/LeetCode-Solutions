#include<iostream>
using namespace std;
void rec_bubble_sort(int arr[], int n){
    if(n == 1) return;
    int didswap = 0;
    for(int i = 0; i<=n-2; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            didswap = 1;
        }
    }
    if(didswap == 0) return;
    rec_bubble_sort(arr, n - 1);
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    rec_bubble_sort(arr, n);
    cout << "The sorted array is: " << endl;
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
