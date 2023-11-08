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
		char arr[8][8];
		int found = 0;

		for(int row = 0; row<8; row++)
			for(int col = 0; col<8; col++)
				cin>>arr[row][col];

		for(int row = 1; row<7 && !found; row++)
			for(int col = 1; col<7; col++){
				if( arr[row][col] == '#'
					&& arr[row-1][col+1] == '#'
					&& arr[row-1][col-1] == '#'
					&& arr[row+1][col+1] == '#'
					&& arr[row+1][col-1] == '#')
				{
					found = 1;
					cout<<row+1<<" "<<col+1<<endl;
					break;
				}
			}
		
     }
}

int main(){
	BOOST;
	solve();

	return 0;
}
