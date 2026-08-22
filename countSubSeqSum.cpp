#include<iostream>
#include<vector>
using namespace std;

int printSub(int idx, int currSum, int sum, int n, int arr[]){
    // Base Case: 
    if(idx == n){
        return (currSum == sum) ? 1 : 0;
    }


    // pick
    int l = printSub(idx + 1, currSum + arr[idx], sum, n, arr);
    // non - pick
    int r = printSub(idx + 1, currSum, sum, n, arr);

    return l + r;
}
int main(){
    int arr[] = {1, 2, 1};
    int n = 3;

    int sum = 2;
    cout << printSub(0, 0, sum, n, arr);
    cout << endl;
    return 0;
}