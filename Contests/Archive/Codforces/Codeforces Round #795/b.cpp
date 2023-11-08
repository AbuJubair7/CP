/*
Author: Jubair_7
Date: 31 May 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define pb push_back
#define ss second
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
		int p = 1;
		int n;
		cin>>n;
		int arr[n];
		int index[n];
		FOR(i, n) {
			cin>>arr[i];
			index[i] = i+1;
		}

		vector<int> v;
		map<int, int> mp;

		for(int i = 0; i<n-1; i++){
			if(arr[i] == arr[i+1]){
				v.push_back(index[i+1]);
				swap(index[i], index[i+1]);
				mp[i+1]++;
				mp[i]++;
			}else{
				if(mp[i] != 0){
					v.push_back(index[i]);
				}else{
					p = 0;
					break;
				}
			}
		}	

		v.push_back(index[n-1]);
		if(mp[n-1] == 0) p = 0;

		if(p){
			for(auto i : v){
				cout<<i<<" ";
			}
			cout<<endl;
		}else cout<<-1<<endl;	 		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
