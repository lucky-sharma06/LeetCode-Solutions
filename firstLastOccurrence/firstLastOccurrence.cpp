#include<iostream>
using namespace std;

int countOccurence(int arr[], int n, int target){
    int low = 0;
    int high = n - 1;
    int first = -1;
    int last = -1;
    // first 
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            // we need to get smallest index possible 
            first = mid;
            high = mid - 1;
        }
        else if(target > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(first == -1) return 0;

    // last 
    low = 0;
    high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            // largest index possible
            last = mid;
            low = mid + 1;
        }
        else if(target > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last - first + 1;

}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int target;
    cin >> target;

    int count = countOccurence(arr, n, target);
    cout << "The count is: " << count << endl;
    return 0;    
}