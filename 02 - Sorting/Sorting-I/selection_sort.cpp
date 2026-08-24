#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int arr[n];
    int i, j;
    cout << "Enter the elements of the array: " << endl;
    for(i = 0; i<n; i++){
        cin >> arr[i];
    }
    for(i = 0; i<=n-2; i++){
        int mini = i;
        for(j = i; j<=n-1; j++){
                if(arr[j] < arr[mini])
                    mini = j;
        }
        swap(arr[i], arr[mini]);
    }
    cout << "The sorted array is: " << endl;
    for(i = 0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
