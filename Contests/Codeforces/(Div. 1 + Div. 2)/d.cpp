/*
Author: jubair7
Date: 27 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool isSorted(vector<int> &arr){
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

void solve(){
   
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}