#include<iostream>
using namespace std;
void rec_insertion_sort(int arr[], int i, int n){
    // base condition
    if(i == n) return;
    int j = i;
    while(j>0 && arr[j-1] > arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }
    rec_insertion_sort(arr, i + 1, n);
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
    rec_insertion_sort(arr, 0, n);
    cout << "The sorted array is: " << endl;
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}
