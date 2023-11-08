/*
Author: jubs
Date: 13 sep 2022
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

		unordered_map<char, vector<int>> map;
		for(int i = 0; i<s.length(); i++){
			map[s[i]].pb(i+1);
		}

		set<char> set;
		set.insert(s[0]);

		vector<char> chars;
		chars.pb(s[0]);
		


		if(s.length() == 2){
			cout<<abs(s[0]-s[1])<<" 2"<<endl;
			cout<<1<<" "<<2<<endl;
		}else{

			int cost = 0, tiles = 2;

			string sub = s.substr(1,s.length()-2);
			sort(sub.begin(), sub.end());

			if(s[s.length()-1] == s[0]){
				cost = 0;

			}else if(s[0] < s[s.length()-1]){
				

				char past = s[0];

				for(int i = 0; i<sub.length(); i++){

					if(sub[i] >= s[0] and sub[i] <=s[s.length()-1]){
						if(past == s[0])
							 cost += (abs(past - sub[i]));
						else 
							cost += abs(sub[i] - past);
		
						past = sub[i];
						
						if(set.count(sub[i]) == 0){
							chars.pb(sub[i]);
						}
						set.insert(sub[i]);
						tiles++;

					}
				}
				cost += (abs(past - s[s.length()-1]));
				
			}else{
				char past = s[0];

				for(int i = sub.length()-1; i>=0; i--){

					if(sub[i] <= s[0] and sub[i] >=s[s.length()-1]){
						if(past == s[0])
							 cost += (abs(past - sub[i]));
						else 
							cost += abs(sub[i] - past);
		
						past = sub[i];
						
						if(set.count(sub[i]) == 0){
							chars.pb(sub[i]);
						}
						set.insert(sub[i]);
						tiles++;

					}
				}
				cost += (abs(past - s[s.length()-1]));
			}

			if(cost == 0){
				cout<<0<<" "<<map[s[0]].size()<<endl;
				for(int i = 0; i<map[s[0]].size();i++){
					cout<<map[s[0]][i]<<" ";
				}
				cout<<endl;
			}else{

				if(set.count(s[s.length()-1]) == 0){
					set.insert(s[s.length()-1]);
					chars.pb(s[s.length()-1]);
				}
				cout<<cost<<" "<<tiles<<endl;

				

				for(auto i: chars){
					for(auto j : map[i]){
						cout<<j<<" ";
					}
				}

				
				cout<<endl;
			}

		}
		
	}
}

int main(){
	BOOST;
	
	solve();
	return 0;
}

