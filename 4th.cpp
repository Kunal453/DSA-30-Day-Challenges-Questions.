#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &arr) {
    vector<int> a,b; 
    for(auto x:arr) {
        if(x<0) {
            a.push_back(x);
        }
        else {
            b.push_back(x);
        }
    }
    arr={};
    for(auto x:a) {
        arr.push_back(x);
    }
    for(auto x:b) {
        arr.push_back(x);
    }
}
int main() {
    vector<int> arr={10, -5, 7, -3, 0, -8};
    func(arr);
    for(auto x:arr) {
        cout<<x<<" ";
    }
    return 0;
}