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
    for(i = n - 1; i>=1; i--){
        int didswap = 0;
        for(j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                //swap(arr[j], arr[j+1]);
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didswap = 1;
            }
        }
        if(didswap == 0)
            break;
        // if swap does not happen then we can say that the array is sorted
    }
    cout << "The sorted array is: " << endl;
    for(i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}



