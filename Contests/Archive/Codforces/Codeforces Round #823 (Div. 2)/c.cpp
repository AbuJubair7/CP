/*
Author: jubs
Date: 25 Sep 2022
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
		string s;
		cin>>s;

		int visited[s.length()+1];
		memset(visited, 0, sizeof(visited));

		string test = s;

		for(int i = 1; i<s.length(); i++){

			if(s[i] < s[i-1]){

				for(int j = i-1; j >=0; j--){
			
					if(s[j] > s[i]){
						if(s[j] != '9' and visited[j] == 0) s[j]++;
						visited[j] = 1;
					}else break;
				}
				
			}
		}

	
		sort(s.begin(), s.end());
		cout<<s<<endl;
		
	}
}

int main(){
	BOOST;
	solve();
	
	return 0;
}

