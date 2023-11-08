/*
Author: Jubair_7
Date: 17 June 2022
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
		ll n, last = -1, pairs;
		cin>>n;

		char arr[n];

		FOR(i, n)cin>>arr[i];
		
		pairs = n;

		for(ll i = 1;i<n; i++){
			if(arr[i] != arr[i-1]){
				pairs += i;
			}
			
		}

		 cout<<pairs<<endl;
		
	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
