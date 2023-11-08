/*
Author: Jubair_7
Date: 23 Apr 2022
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
	return (a*b)/gcd(a,b);
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		string s;
		int ok = 1;
		cin>>s;

		int cb = 0, ca = 0;
		for(int i = 0; i<s.size(); i++){
			if(s[i] == 'B') cb++;
			else ca++;
			if(cb > ca) ok = 0;
		}

		if(s[s.size() - 1] != 'B') ok = 0;
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
