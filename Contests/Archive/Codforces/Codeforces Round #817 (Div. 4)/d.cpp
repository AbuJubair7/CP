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

bool compare(pair<ll, ll> p1, pair<ll, ll> p2){
	return p1.second < p2.second;
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		
		ll n;
		ll sum =  0;
		cin>>n;
		vector<pair<ll , ll>> vc;

		char arr[n];
		FOR(i, n){
			
			cin>>arr[i];
			if(arr[i] == 'L'){
				vc.pb({i+1,i});
				sum += i;
			}else{
				vc.pb({i+1, n-i-1});
				sum += (n-i-1);

			}

		}
		//cout<<sum<<endl;

		sort(vc.begin(), vc.end(), compare);
		// for(auto i : vc){
		// 	cout<<i.second<<" ";
		// }
		// cout<<endl;

		ll count = 1;
		ll index = 0;

		while(count <= n){
			int tempSum = sum;
			ll i = 1;
			if(arr[vc[index].first-1] == 'L'){
				if(vc[index].first <= floor(n/2)){
				//	cout<<"changing: "<<vc[index].first<<endl;
					sum -= vc[index].second;
					sum += (n - (vc[index].first));
				}
			}else{
				// looking 'Right'
				if(vc[index].first > ceil(n/2)){
					//cout<<"changinG: "<<vc[index].first<<" "<<arr[vc[index].first-1]<<endl;
					sum -= vc[index].second;
					sum += ((vc[index].first)-1);
				}
			}
			index++;
			count++;
			//cout<<"sum: "<<sum<<" "; 
			cout<<sum<<" ";
		}
		cout<<endl;



	}
}

int main(){
	BOOST;
	solve();
	vector<int> vc(3,0);


	return 0;
}

