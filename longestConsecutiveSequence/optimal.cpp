#include<iostream>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "The longest consecutive sequence is: " << endl;
    
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            // previous is not there so it is starting
            int cnt = 1;
            int x = it;
            while(st.find(x + 1) != st.end()){
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return 0;

}