#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "The longest consecutive sequence is: " << endl;
    // sort
    sort(arr, arr + n);

    int longest = 1;
    int cnt = 0;
    int lastSmallest = INT_MIN;
    int st = 0; 
    int end = 0;
    int bestSt = 0;
    int bestEnd = 0;
    for(int i = 0; i < n; i++){

        if(arr[i] == lastSmallest + 1){
            cnt++;
            lastSmallest = arr[i];
            end = i;
        }
        else if(arr[i] != lastSmallest){
            st = i;
            end = i;
            cnt = 1;
            lastSmallest = arr[i];
        }
        if(cnt > longest){
            longest = cnt;
            bestSt = st;
            bestEnd = end;
        }
    }
    cout << longest << endl;
    cout << "The sequence is: " << endl;
    for(int i = bestSt; i <= bestEnd; i++){
        if(i > bestSt && arr[i] == arr[i - 1]) continue;
        cout << arr[i] << " ";
    }
    return 0;

}