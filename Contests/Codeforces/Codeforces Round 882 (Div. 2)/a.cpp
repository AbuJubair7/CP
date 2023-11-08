/*
Author: jubair7
Date: 17 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		priority_queue<int> q;
 		for(auto &i : arr) cin >> i;
 		for(int i = 1; i<n; i++){
 			q.push(abs(arr[i]-arr[i-1]));
 		}
 		k--;
 		while(k--)	q.pop();
 		int sum = 0;
 		while(!q.empty()){
 			sum += q.top();
 			q.pop();
 		}
 		cout << sum << "\n";
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}