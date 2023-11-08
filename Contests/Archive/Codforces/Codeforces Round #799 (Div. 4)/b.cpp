/*
Author: Jubair_7
Date: 14 June 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

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

		int arr[n];
		map<int, int> mp;
		std::vector<int> v;

		FOR(i, n) cin>>arr[i];
		
		FOR(i, n) mp[arr[i]]++;

		int length = 0;
		int even=  0;

		for(map<int, int>::iterator it  = mp.begin(); it != mp.end(); it++){
			if(it->second % 2 != 0) length++;
			else{
				even++;
			}
		
		}

		if(even %2 == 0) length+=even;
		else length += (even-1);
		
		cout<<length<<endl;
		

     }
}

int main(){
	BOOST;
	solve();

	return 0;
}
