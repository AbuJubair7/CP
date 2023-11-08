/*
Author: jubair7
Date: 18 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
       int n, k, x;
       cin >> n >> k >> x;
       int sum = 0;
       if ((n-1) < k-1 or x < k-1) cout << -1 << '\n';
       else {
         if (x == k) x--;
         for (int i = 0; i<n; i++)
            if (i < k) sum += i;
            else sum += x;
         cout << sum << '\n';
       }
      
    }
  return 0;
}