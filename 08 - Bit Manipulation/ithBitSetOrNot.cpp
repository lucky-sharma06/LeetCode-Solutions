#include<iostream>
using namespace std;
// set the ith bit n | (1 << i);
// clear the ith bit (n & ~(i << i)) 
// for toggle the ith bit n ^ (1 << i);
// to remove the rightmost set bit n & n - 1
// to check if the number is power of 2 or not => (n & n - 1) == 0 means yes
int main(){
    int n = 13;
    int i = 1;

    if((n & (1 << i)) != 0){
        cout << "set" << endl;
    }
    else
        cout << "not set" << endl;
    return 0;
}

