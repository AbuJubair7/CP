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
		int a, b, c;
		cin >> a >> b >> c;
		if(a + b >= 10) cout << "YES" << '\n';
		else if(a + c >= 10) cout << "YES" << '\n';
		else if(b + c >= 10) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}