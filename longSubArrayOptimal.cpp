#include<iostream>
#include<vector>
using namespace std;
int Optimal(const vector<int> &vec, int k){
    int left = 0, right = 0; 
    int maxLen = 0, sum = vec[0]; 
    int n = vec.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= vec[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += vec[right]; // if right is at last element and right++ then it will be garbage value
    }
    return maxLen;
}
int main(){
    vector<int> vec = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k;
    cin >> k;
    int result = Optimal(vec, k);
    cout << result;
    return 0;
}