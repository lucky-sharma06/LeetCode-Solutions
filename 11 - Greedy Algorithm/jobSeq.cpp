#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct job{
    int id, dead, profit;
};
bool comp(job a, job b){
    if(a.profit > b.profit) return true;
    else return false;
}
vector<int> jobSeq(int jid[], int deadline[], int profit[], int n){
    job arr[n];
    int totProfit = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        arr[i].id = jid[i];
        arr[i].dead = deadline[i];
        arr[i].profit = profit[i];
    }

    sort(arr, arr + n, comp);

    int maxDeadline = -1;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> vec(maxDeadline + 1, -1);

    for(int i = 0; i < n; i++){
        for(int j = arr[i].dead; j > 0; j--){
            if(vec[j] == -1){
                cnt++;
                vec[j] = arr[i].id;
                totProfit += arr[i].profit;
                break;
            }
        }
    }
    cout << "The number of jobs allocated are: " << cnt << endl;
    cout << "The total profit is: " << totProfit << endl;
    return vec;

}
int main(){
    int n = 7;
    int id[] = {1, 2, 3, 4, 5, 6, 7};
    int deadline[] = {2, 1, 2, 1, 3, 3, 2};
    int profit[] = {100, 19, 27, 25, 15, 30, 50};

    vector<int> ans = jobSeq(id, deadline, profit, n);
    cout << "The ans is: " << endl;
    for(int i = 1; i < ans.size(); i++){
        if(ans[i] != -1){
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;

}