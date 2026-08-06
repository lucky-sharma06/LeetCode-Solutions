#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Data{
    int st, end, pos;
};
bool comp(Data d1, Data d2){
    return d1.end < d2.end;
}
vector<int> maxMeetings(int start[], int end[], int n){
    Data arr[n];
    for(int i = 0; i < n; i++){
        arr[i].st = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    } // initialized the array

    sort(arr, arr + n, comp);

    vector<int> ans;
    int cnt = 1;
    int freeTime = arr[0].end;
    ans.push_back(arr[0].pos);
    
    for(int i = 1; i <= n - 1; i++){
        if(arr[i].st > freeTime){
            // allocate the meeting
            freeTime = arr[i].end;
            cnt++;
            ans.push_back(arr[i].pos);
        }
    }

    return ans;

}
int main(){
    int n = 6;
    int start[n] = {0, 3, 1, 5, 5, 8};
    int end[n] = {5, 4, 2, 9, 7, 9};

    vector<int> ans = maxMeetings (start, end, n);
    cout << "Max Meetings: " << ans.size() << endl;
    cout << "Meeting order: " << endl;
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}