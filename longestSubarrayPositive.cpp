#include<iostream>
using namespace std;
int brute(int arr[], int n, int num){
    int length = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == num) length = max(length, j - i + 1);
        }
    }
    return length;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int result = brute(arr, n, 3);
    cout << result;
}