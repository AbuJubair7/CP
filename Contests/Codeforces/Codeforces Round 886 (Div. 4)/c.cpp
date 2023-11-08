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
		vector<string> arr;
		for(int i = 0; i<8; i++){
			string s;
			cin >> s;
			arr.push_back(s);
		}
		string res = "";
		for(int i = 0; i<8; i++){
			for(int j = 0; j<8; j++){
				if(arr[i][j] != '.')
					res += arr[i][j];
			}
		}
		cout << res << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}