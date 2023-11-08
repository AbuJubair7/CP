/*
Author: jubair7
Date: 16 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

const int mod = 1e9+7;

void solve(){
	vector<char> s;
	vector<char> p;
	vector<char> m;
	for(int i = 0; i<3; i++){
		string str;
		cin >> str;
		if(str[1] == 's')
			s.push_back(str[0]);
		else if(str[1] == 'p')
			p.push_back(str[0]);
		else 
			m.push_back(str[0]);
	}

	sort(s.begin(), s.end());
	sort(p.begin(), p.end());
	sort(m.begin(), m.end());
	int ok = 0;
	int sNeed = INT_MAX;
	int pNeed = INT_MAX;
	int mNeed = INT_MAX;
	if(s.size() == 3){
		if((s[0] == s[1] and s[0] == s[2]) or
			(s[0] + 1 == s[1] and s[1]+1 == s[2])){
			ok = 1;
		}else{
			if(s[0] == s[1] or s[1] == s[2])
				sNeed = 1;
			else if(s[0] + 1 == s[1] or s[1] + 1 == s[2])
				sNeed = 1;
			else if(s[0] + 2 == s[1] or s[1] + 2 == s[2])
				sNeed = 1;
			else sNeed = 2;
		}
	}else if(p.size() == 3){
		if((p[0] == p[1] and p[0] == p[2]) or
			(p[0] + 1 == p[1] and p[1]+1 == p[2])){
			ok = 1;
		}else{
			if(p[0] == p[1] or p[1] == p[2])
				pNeed = 1;
			else if(p[0] + 1 == p[1] or p[1] + 1 == p[2])
				pNeed = 1;
			else if(p[0] + 2 == p[1] or p[1] + 2 == p[2])
				pNeed = 1;
			else pNeed = 2;
		}
	}else if(m.size() == 3){
		if((m[0] == m[1] and m[0] == m[2]) or
			(m[0] + 1 == m[1] and m[1]+1 == m[2])){
			ok = 1;
		}else{
			if(m[0] == m[1] or m[1] == m[2])
				mNeed = 1;
			else if(m[0] + 1 == m[1] or m[1] + 1 == m[2])
				mNeed = 1;
			else if(m[0] + 2 == m[1] or m[1] + 2 == m[2])
				mNeed = 1;
			else mNeed = 2;
		}
	}
	if(ok) cout << 0 << '\n';
	else{
		
		if(s.size() == 1) sNeed = 2;
		else if(s.size() == 2){
			if(s[0] == s[1] or s[0]+1 == s[1] or s[0]+2 == s[1])
				sNeed = 1;
			else sNeed = 2;
		}
		if(p.size() == 1) pNeed = 2;
		else if(p.size() == 2){
			if(p[0] == p[1] or p[0]+1 == p[1] or p[0]+2 == p[1])
				pNeed = 1;
			else pNeed = 2;
		}
		if(m.size() == 1) mNeed = 2;
		else if(m.size() == 2){
			if(m[0] == m[1] or m[0]+1 == m[1] or m[0]+2 == m[1])
				mNeed = 1;
			else mNeed = 2;
		}

		cout << min(min(sNeed, mNeed), pNeed) << '\n';
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  //solve2();	
  return 0;
}