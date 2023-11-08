/*
Author: jubs
Date: 12 sep 2022
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
		int n;
		cin>>n;
		string code;
		cin>>code;

		string s;
		for(int i = code.length()-1; i>=0; i--){
			if(code[i] == '0'){
				
				string temp;
				temp += code[i-2];
				temp += code[i-1];

				int vl = stoi(temp);

				char ch  = 96 + vl;
				s += ch;

				i -= 2;

			}else{
				string temp;
				temp += code[i];

				int vl = stoi(temp);
				char ch  = 96 + vl;
				s += ch;
			}
		}

		reverse(s.begin(), s.end());
		cout<<s<<endl;
		
	}
}

int main(){
	BOOST;
	solve();


	return 0;
}

