/*
Author: jubair7
Date: 19 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		string ans = "";
		if(s1[0] == s2[0] and s2[0] == s3[0] and s1[0] != '.'){
			ans += s1[0];
		}else if(s1[1] == s2[1] and s2[1] == s3[1] and s1[1] != '.'){
			ans += s1[1];
		}else if(s1[2] == s2[2] and s2[2] == s3[2] and s1[2] != '.'){
			ans += s1[2];
		}else if(s1[0] == s1[1] and s1[1] == s1[2] and s1[0] != '.'){
			ans += s1[0];
		}else if(s2[0] == s2[1] and s2[1] == s2[2] and s2[0] != '.'){
			ans += s2[0];
		}else if(s3[0] == s3[1] and s3[1] == s3[2] and s3[0] != '.'){
			ans += s3[0];
		}else if(s1[0] == s2[1] and s2[1] == s3[2] and s1[0] != '.'){
			ans += s1[0];
		}else if(s1[2] == s2[1] and s2[1] == s3[0] and s1[2] != '.'){
			ans += s1[2];
		}else{
			ans += "DRAW";
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