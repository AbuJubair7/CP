/*
Author: jubs
Date: 23 Sep 2022
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
		ll n;
		cin>>n;

		char arr[n+1];
		vector<int> v;
		int visited[n+1];
		memset(visited, 0, sizeof(visited));
		map<int, int> map;
		

		for(int i = 1; i<=n; i++){
			cin>>arr[i];
		}
		int need = 0;
		for(int i = 1; i<=n; i++){
			if(arr[i] == '0') {
				v.pb(i);
				need++;
			}
		}

		if(v.size() == 0) cout<<0<<endl;
		else if(v.size() == 1) cout<<v[0]<<endl;

		else{

			ll ans = 0;
			int need = v.size();

			for(ll i = 0; i<v.size(); i++){
				if(need == 0) break;
				int k = v[i];
				for(int j = k; j<=n; j+=k){
					if(arr[j] == '1'){
						break;
					}else{
						if(visited[j] == 0){
							ans += k;
							visited[j] = 1;
							need--;
						}
					}
					
				}
			}
			cout<<ans<<endl;
		}

	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

