/*
Author: Jubair_7
Date: 11 May 2022
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
		ll n, query;
		cin>>n>>query;
		ll total = 0;
		vector<ll> v(n);

		for(int i = 0 ;i <n ;i++){
			cin>>v[i];
			total += v[i];
		}

		sort(v.begin(), v.end());
		
		int count= 0 ;
		int sum = 0;

		for(int i = 0; i<query ; i++){
			int q;
			cin>>q;

			if(q == total) cout<<n<<endl;
			else if(v[n-1] >= q) cout<<1<<endl;
			else if(total < q) cout<<-1<<endl;
			else{
				for(int j = n-1 ; j>=0;j--){
					sum += (v[j]);
					count++;
					if(sum >= q){
						cout<<count<<endl;
						sum = 0;
						count = 0;
						//got = 1;
						break;
					}
				}	
			}

			

			// if(!got) cout<<-1<<endl;
			// got = 0;
			// count = 0;
			// sum = 0;

		}
		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
