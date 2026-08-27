#include<iostream>
#include<vector>
using namespace std;

bool printSub(int idx, int currSum, int sum, int n, int arr[], vector<int>& ds){
    // Base Case: 
    if(idx == n){
        if(currSum == sum){
            // Condition satisfied
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else return false;
    }

    // pick
    ds.push_back(arr[idx]);
    if(printSub(idx + 1, currSum + arr[idx], sum, n, arr, ds) == true) return true;
    ds.pop_back();

    // non - pick
    if(printSub(idx + 1, currSum, sum, n, arr, ds)) return true;

    return false;
}
int main(){
    int arr[] = {1, 2, 1};
    int n = 3;

    vector<int> ds;
    int sum = 2;
    printSub(0, 0, sum, n, arr, ds);
    return 0;
}