#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minPlatform(int arr[], int dept[], int n){
    int A = 0, D = 0;
    int maxCnt = 0;
    int cnt = 0;
    while(A < n){
        if(arr[A] <= dept[D]){
            cnt++;
            A++;
        }
        else{
            cnt--;
            D++;
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