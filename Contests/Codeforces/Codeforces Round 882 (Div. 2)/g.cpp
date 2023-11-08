/*
Author: jubair7
Date: 20 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;


void solve(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n+10);
		long long sum = (n * (n +1)) / 2;
		if(n == 1) cout << 1 << '\n';
		else if(n == 2) cout << 2 << " " << 1 << '\n';
		else if(n % 2 == 0){
			int div = sum / 2;
			int i = 1; int j = n;
			while(i < j){
				v[i] = j;
				v[j] = j-1;
				v[i+1] = i;
				v[j-1] = i+1;
				i+=2;
				j-=2;
			}
			for(int i = 1; i<=n; i++) cout << v[i] << ' ';
			cout << '\n';
		}else  cout << -1 << '\n';		
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}