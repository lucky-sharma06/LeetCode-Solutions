#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double fracKnap(vector<pair<int, int>>& arr, int W){
    double totValue = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].second <= W){
            // poora lelo
            totValue += arr[i].first;
            W -= arr[i].second;
        }
        else{
            // take the fraction
            totValue += ((((double) arr[i].first) / ((double) arr[i].second)))*W;
            break;
        }
    }
    return totValue;
}
bool comp(pair<int, int> p1, pair<int, int> p2){
    // first -> value
    // second -> weight
    // by defualt if x == y it means don't do anything
    // x > y means x comes before y
    // x < y means x does not comes before y
    double x = (double) p1.first / (double) p1.second;
    double y = (double) p2.first / (double) p2.second; 
    return x > y;
}
int main(){
    int W; 
    cout << "Enter the weight of the knapsack: " << endl;
    cin >> W;

    // let n = 4;

    vector<int> value = {100, 60, 100, 200};
    vector<int> weight = {20, 10, 50, 50};

    // start
    int n = value.size();
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++){
        arr.push_back({value[i], weight[i]});
    }

    sort(arr.begin(), arr.end(), comp);
    for(auto it : arr){
        cout << it.first << "," << it.second << " ";
    }
    cout << endl;
    cout << fracKnap(arr, W) << endl;
    return 0;



}