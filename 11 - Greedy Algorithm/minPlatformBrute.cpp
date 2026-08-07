#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool checkIntersection(int arr[], int dept[], int n, int i, int j){
    // i is the first 
    // j is the second
    return (arr[j] <= dept[i] && dept[j] >= arr[i]);
}
int minPlatform(int arr[], int dept[], int n){
    int maxCnt = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = i + 1; j < n; j++){
            if(checkIntersection(arr, dept, n, i, j)){
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}
int main(){
    int n = 6;
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dept[] = {920, 1200, 1150, 1150, 1900, 2000};

    cout << "Minimum platforms required is: " << minPlatform(arr, dept, 6) << endl;
    return 0;
}