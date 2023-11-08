/*
Author: Jubair_7
Date: 10 May 2022
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

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		int n, m;
		cin>>n>>m;

		vector<string> v(n);

		for(ll i = 0; i<n ; i++){
			cin>>v[i];
		}

		int dif = 0;
		int min = INT_MAX;

		for(int i = 0; i<n ;i++){
		
			for(int j = 0; j<n-1 ;j++){

				if(j != i){
				
					string s = v[i];
					string s2 = v[j];

					// cout<<"s: "<<s<<endl;
					// cout<<"s2: "<<s2<<endl;

					for(int q = 0; q<m; q++){
						
						dif += (abs(s[q] - s2[q]));
					}
					if(dif <= min) min = dif;
				//	cout<<"min: "<<min<<" j: "<<j<<endl;	
					dif = 0;		
				}
				
				
				
				
			}
		}

		cout<<min<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
