/*
Author: Jubair_7
Date: 4 June 2022
*/
#include <bits/stdc++.h>
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
bool checkSqurt(int n){
	int left = 1, right =n;

	while(left <= right){
		int mid = (left+right)/2;
		if(mid *  mid == n){
			return true;
		}else if(mid * mid > n){
			right = mid-1;
		}else left = mid+1;
	}

	return false;
}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;
	while(t--){
	// 	long long m; 
	// int n; 
	// cin >> n >> m;
	// vector<long long> v(n); 
	// for(int i =0 ; i < n; i++){
	// 	cin >> v[i];
	// }
	
	// sort(v.begin(), v.end());
	// long long sum = 0;
	// for(int i = n-2; i >= 1; i--){
	// 	sum += v[i] + 1; 
	// }
	// sum += v[n-1] * 2 + 2;
	// if( sum <= m){
	// 	cout << "YES" << endl; 
	// }
	// else{
	// 	cout << "NO" << endl; 
	// }

		cout<<t<<endl;

	}

	
}

int main(){
	BOOST;
	solve();
	//cout<<5%3<<endl;
	return 0;
}
