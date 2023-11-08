/*
Author: Jubair_7
Date: 13 May 2022
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

		char arr[n][m];

		for(int i = 0;i <n ; i++){
			for(int j = 0; j<m ;j++){
				cin>>arr[i][j];
			}
		}

		int possible = 0;
		if(arr[0][0] == 'R'){
			 possible = 1;
		}
		else{
			int mostLeft = INT_MAX;
			int mostTop = INT_MAX;

			for(int row = 0 ; row<n ; row++){
				int found = 0;
				for(int col = 0; col<m ; col++){
					if(arr[row][col] == 'R'){
						mostTop = col;
						found = 1;
						break;
					}
				}
				if(found) break;
			}

			for(int row = n-1; row>=0; row--){
			
				for(int col = m-1; col>=0 ; col--){
					if(arr[row][col] == 'R'){
						if(col <= mostLeft){
							 mostLeft = col;
							
						}
					}
				}
			
			}

			if(mostTop <= mostLeft) possible = 1;
			else possible = 0;
		}

		if(possible) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
