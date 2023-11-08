/*
Author: jubair7
Date: 16 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		int ok = 1;
		int x, y;
		cin >> x >> y;
		for(int i = 0; i<k; i++){
			int a, b;
			cin >> a >> b;
			if((abs(a-x) + abs(b-y)) % 2 == 0)
				ok = 0;
		}
		if(ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}