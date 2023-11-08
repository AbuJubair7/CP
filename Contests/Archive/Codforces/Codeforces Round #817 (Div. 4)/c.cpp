/*
Author: jubs
Date: 30 Aug 2022
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
		string arr[3][n];

		map<string, int> map1;

		map<string, vector<int>> map2;

		vector<int> vc(3,0);

		for(int i = 0; i<3; i++){
			for(int j = 0; j<n; j++){
				cin>>arr[i][j];
				 map1[arr[i][j]]++;
				 map2[arr[i][j]].pb(i);
			}
		}

		for(auto m : map1){
			if(m.second == 1){
		
				vc[map2[m.first][0]] += 3;
			}else if(m.second == 2){
				for(auto data :  map2[m.first]){
					vc[data] += 1;
				}
			}
		}

		for(auto i : vc){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

