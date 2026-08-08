#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n = 5;
    int arr[] = {4, 3, 7, 1, 2};
    // arrival time for all is 0
    sort(arr, arr + n);
    int wtTime = 0;
    int waitSum = 0;
    int timer = 0;
    for(int i = 0; i < n; i++){
        wtTime = timer;
        timer += arr[i];
        waitSum += wtTime;
    }
    float avg = (waitSum)/(float) n;
    cout << "The average waiting time is: " << avg << endl;
    return 0;
}