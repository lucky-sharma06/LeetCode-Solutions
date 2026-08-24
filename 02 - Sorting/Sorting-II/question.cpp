#include <iostream>
using namespace std;
// Bhavya Sharma E223
bool subsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main() {
    int n, sum;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Enter target sum: ";
    cin>>sum;
    if (subsetSum(arr, n, sum))
        cout<<"Subset with given sum exists.";
    else
        cout<<"Subset with given sum does not exist.";

    return 0;
}
