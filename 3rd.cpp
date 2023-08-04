// Given an array arr[] of non-negative integers and an integer sum, find a subarray that adds to a given sum. There may be more than one subarray with sum as the given sum, print first such subarray.

#include<iostream>
using namespace std;

// Using Nested For Loops => Time Complexity: O(n2)
void subarraysum(int arr[], int n, int target) {
  int sum = 0;
  int flag = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == target) {
      cout<<"The target is obtained at index "<<i<<endl;
      return;
    }
    sum = arr[i];
    for(int j=i+1; j<n; j++) {
      if(sum == target) {
        cout<<"The target is obtained between index "<<i<<" and "<<j-1<<endl;
        flag = 1;
        return;
      }
      if(sum > target) {
        break;
      }
      sum = sum + arr[j];
    }
}
  if(flag == 0) {
    cout<<"The target is not present in array \n";
  }
}

bool slidingwindow(int arr[], int n, int target) {
  int start = 0;
  int sum = arr[0];
  for(int i=1; i<=n; i++) {
    while(sum > target && start < (i - 1)) {
      sum = sum - arr[start];
      start++;
    }
  if(sum == target) {
    return true;
  }
  if(i < n) {
    sum = sum + arr[i];
  }
  }
  return false;
}

int main() {
  int arr[] = {6, 7, 1, 4, 1, 8, 2};
  int target = 8;
  int size = sizeof(arr)/sizeof(int);
  subarraysum(arr, size, target);
  if(slidingwindow(arr, size, target)) {
    cout<<"There is a subarray present whose sum is equal to target"<<endl;
  }
  return 0;
}