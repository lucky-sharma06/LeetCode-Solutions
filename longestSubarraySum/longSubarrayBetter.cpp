#include<iostream>
#include<map>

using namespace std;
int better(int arr[], int n, int k){
    map<long, int> hashMap;
    long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        long prevSum = sum - k;
        if(sum == k){
            // this means from index 0 to current the sum is k hence it is the subarray
            maxLen = max(maxLen, i + 1);
            //  this is the safer option 
            // maxLen = i + 1; this might be not safer but i don't think so this works fine
        }
        if(hashMap.find(prevSum) != hashMap.end()){
            // means now subarray exist from the index of the prevSum to the current location
            int len = i - hashMap[prevSum];
            maxLen = max(maxLen, len);
        }
        if(hashMap.find(sum) == hashMap.end()){
            // means sum is not in the map already
            hashMap[sum] = i;
        }
    }
    return maxLen;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int result = better(arr, n, k);
    cout << result;
    return 0;
}