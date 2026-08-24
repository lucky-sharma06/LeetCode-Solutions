#include<iostream>
using namespace std;
int main(){
    int n;
    int temp;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    int i, j;
    for(i = 0; i<n; i++){
        cin >> arr[i];
    }
    for(i = 0; i<=n-1; i++){
        j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    cout << "The sorted array is: " << endl;
    for(i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
