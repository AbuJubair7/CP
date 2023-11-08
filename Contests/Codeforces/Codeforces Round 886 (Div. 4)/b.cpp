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
		int n;
		cin >> n;
		int win = 0;
		int ind = 0;
		int i = 1;
		while(i <= n){
			int a, b;
			cin >> a >> b;
			if(a <= 10){
				if(b > win){
					win = b;
					ind = i;
				}
			}
			i++;
		}
		cout << ind << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}