/*
Author: jubair7
Date: 19 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

const int mx = 1e6;
const int root = sqrt(mx);
bitset<mx> can;

void solve(){
	int t;
	cin>>t;
	for(int i = 2; i<=root; i++){
		int ans = 0;
		int top = i*i;
		ans += (top + i);
		while(ans < mx){
			can[ans+1] = 1;
			top *= i;
			ans += top;
		}
	}
	while(t--){
		int n;
		cin >> n;
		if(can[n]) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}