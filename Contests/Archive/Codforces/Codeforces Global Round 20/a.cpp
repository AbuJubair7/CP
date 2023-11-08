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
		int n;
		cin>>n;
		vector<int> v(n);

		for(int i = 0; i<n; i++){
			cin>>v[i];
		}

		sort(v.begin(), v.end());
		int first = 0;

		string winner = "errorgorn";
		if(v[n-1] == 1){
			winner = "maomao90";
		}else{
			for(int i=n-1; i>=0; i--){
				if(v[i] == 1){
					if(first == 0){
						winner = "maomao90";
						break;
					}else{
						winner = "errorgorn";
						break;
					}
				}else if(v[i] % 2 == 0){
					if(first == 0){
						winner = "errorgorn";
						first = 1;
					}else{
						winner = "maomao90";
						first = 0;
					}
				}
			}

		}
		cout<<winner<<endl;
	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
