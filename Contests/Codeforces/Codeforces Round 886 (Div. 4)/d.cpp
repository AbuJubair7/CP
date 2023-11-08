/*
Author: jubair7
Date: 21 Jul 2023
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
		vector<int> arr2;
		int maxDis = 0;
		int num = 0;
		for(auto &i : arr) cin >> i;
		sort(arr.begin(), arr.end());
		vector<int> d;
		d.push_back(0);
		for(int i = 1; i<n; i++){
			int dis = arr[i]-arr[i-1];
			d.push_back(dis);
		}
		int seg = 0;
		int left = 0;
		int right = 0;
		while(right < d.size()){
			if(d[right] > k){
				seg = max(seg, right-left);
				left = right;
			}else if(right == n-1){
				seg = max(seg, right-left+1);
			}
			right++;
		}
		cout << n-seg << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}