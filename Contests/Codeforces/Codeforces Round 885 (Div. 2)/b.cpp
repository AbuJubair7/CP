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
		cin >> n >>k;
		map<int, vector<int>> c;
		int ans =  INT_MAX;
		int col = -1;
		for(int i = 1; i<=n; i++){
			int col;
			cin >> col;
			c[col].push_back(i);
		}
		for(auto i : c){
			vector<int> v = i.second;
			vector<int> dis;
			int d = INT_MAX;
			dis.push_back(v[0] - 1);
			for(int j = 1; j<v.size(); j++){
				int tmpDis = v[j]-v[j-1]-1;
				if(tmpDis){
					dis.push_back(tmpDis);
				}
			}
			dis.push_back(n - v[v.size()-1]);
			sort(dis.begin(), dis.end(), greater<>());
			d = dis[0];
			int mid = d/2;
			if(dis.size() >= 2){
				if(dis[1] >= mid){
					mid = dis[1];
				}
			}
			ans = min(mid, ans);
		}
		cout << ans << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}