/*
Author: Jubair_7
Date: 17 Apr 2022
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

void swap(ll &a, ll &b){
	ll temp = a;
	a = b;
	b = temp;
}

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
		int n,a,b;
		cin>>n>>a>>b;
		++n;
		vector<int> v(n);
		ll sum=  0;
		for(int i = 1;i <n; i++){
			cin>>v[i];
			sum += v[i];
		}
		ll res = 1e18;

		for(int i = 0; i<n; ++i){
			ll cur = (a+b)*(ll)v[i];
			sum -= v[i];
			cur += (sum-(n-i-1)*(ll)v[i])* b;
			res = min(res, cur);
		}
		cout<<res<<endl;



	}
}

int main(){
	BOOST;
	solve();



	return 0;
}
