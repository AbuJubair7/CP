/*
Author: Jubair_7
Date: 9 Apr 2022
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
		ll v = 49;
		int count = 0;

		if(v*2 > 32768){
			while(true){
				v = (v+1) % 32768;
				if(v == 0)
				break;
			else count++;
			}
		}else{
			while(1){
			v = (v*2) % 32768;
			
			if(v == 0)
				break;
			else count++;
		}

	}

		


		cout<<count+1<<endl;
	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
