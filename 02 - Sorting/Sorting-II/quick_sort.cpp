#include<iostream>
#include<vector>
using namespace std;
int correctIndex(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int partition_index = correctIndex(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}
int main(){
    vector<int> arr;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i<n; i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    quickSort(arr, 0, arr.size() - 1);
    cout << "The sorted array is: " << endl;
    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
