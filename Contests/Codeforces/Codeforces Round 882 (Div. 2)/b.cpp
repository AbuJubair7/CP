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
		int n, m, h;
		cin >> n >> m >> h;
		vector<pair<int, long long>> pos(n);
		vector<long long> same;
		int cnt = 0;
		for(int i = 0; i<n; i++){
			vector<int> min;
			for(int j = 0; j<m; j++){
				int x;
				cin >> x;
				min.push_back(x);
			}
			sort(min.begin(), min.end());
			long long total = 0;
			long long penalty = 0;
			for(int k = 0; k<m; k++){

				total += min[k];
				if(total <= h){
					penalty += (total);
					pos[i].first++;
					pos[i].second = penalty;
				}else break;
			}
			if(i == 0){
				same.push_back(pos[0].second);
			}else{
				if(pos[0].first == pos[i].first)
					same.push_back(pos[i].second);
				else if(pos[i].first > pos[0].first)
					cnt++;
			}
		}
		sort(same.begin(), same.end());
		int tmp = lower_bound(same.begin(), same.end(), pos[0].second) - same.begin() + 1;
		cout << cnt + tmp << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}