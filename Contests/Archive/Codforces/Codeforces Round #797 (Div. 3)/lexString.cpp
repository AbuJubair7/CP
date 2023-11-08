/*
Author: Jubair_7
Date: 11 June 2022
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
		int n, m, k, i = 0, j = 0, removedA = 0, removedB = 0;;
		cin>>n>>m>>k;
		string a, b, c;
		cin>>a>>b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		while(i < n && j < m){
			if(a[i] < b[j]){
				
				if(removedA < k){
					c += a[i];
					removedB = 0;
					removedA++;
					i++;
					
				}else{
					c += b[j];
					removedA = 0;
					removedB++;
					j++;
				}
				
			}else{
				if(removedB < k){
					c += b[j];
					removedA = 0;
					removedB++;
					j++;
				}else{
					c += a[i];
					removedB = 0;
					removedA++;
					i++;
				}
			}
			
		}

		cout<<c<<endl;
	
     }
}

int main(){
	BOOST;
	solve();

	return 0;
}
