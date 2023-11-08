/*
Author: jubair7
Date: 11 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin >> a >> b;
		if(a == 1 and b == 2) cout << 3 << '\n';
		else if(a == 1) cout << 2 << '\n';
		else cout << 1 << '\n'; 
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}