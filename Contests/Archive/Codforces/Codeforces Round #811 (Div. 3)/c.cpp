/*
Author: jubs
Date: 1 Aug 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;



/*........................start.............................*/



void solve(){
	ll t;
	cin>>t;
	while(t--){
		
		int s;
		cin>>s;

		int sum = 0;
		string str;
		if(s < 10) cout<<s<<endl;
		else{
			int i = 9;
			while(true){
				if(sum < s){
					if(sum + i <= s){
						sum += i;
						str += to_string(i);
					}
					if(sum == s) break;
				}
				i--;
			}

			reverse(str.begin(), str.end());
			cout<<str<<endl;
		}
		

	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
