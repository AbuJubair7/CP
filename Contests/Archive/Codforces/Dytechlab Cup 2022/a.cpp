/*............................
Author: Jubair_7
Date: 7 Oct 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const ll value = 1e8;

bool status[value];
vector<ll> primes;

void seive(ll n){
	ll sq = sqrt(n);
	primes.pb(2);

	for(ll i = 4; i<=n; i += 2)
		status[i] = 1;

	for(ll i = 3; i<=sq; i+=2){

		if(!status[i]){
			primes.pb(i);
			for(ll j = i*i; j<=n; j += i)
				status[j] = 1;
		}
	}

	for(ll i = sq+1; i<=n ;i++){
		if(!status[i]){
			primes.pb(i);
		}
	}
}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n, k;
		cin>>n>>k;

		string s;
		cin>>s;

		sort(s.begin(), s.end());

		vector<char> set;
		map<char, int> map;

		for(int i = 0; i<s.length(); i++){
				map[s[i]]++;
		}

		for(auto m : map) set.push_back(m.first);

		string ans = "";

		vector<string> v;

		for(int i = 0; i<=n-(n/k); i += (n/k)){
			string tmp = "";

			for(int j = i; j<=i+(n/k); j++){

				int l = 0, r = set.size()-1;

				while(l <= r){

					l++;
					r
				}

				
			}

			v.push_back(tmp);
		}
	
		
		for(int i = 0; i<v.size(); i++){
			string tmp = v[i];

			sort(tmp.begin(), tmp.end());
			cout<<"Vector: "<<tmp<<endl;
			if(tmp[0] != 'a') ans += 'a';
			else{
				int got = 0;
				for(int j = 1; j<=tmp.size(); j++){
					char c = tmp[j];
					if((c-1) != tmp[j-1]){
						ans += (tmp[j-1]+1);
						got = 1;
						break;
					}
				}

				if(!got) ans += (tmp[tmp.length()-1] + 1);
			}
				
		}

		for(auto i : v) cout<<i<<endl;

		sort(ans.begin(), ans.end());
		cout<<ans<<endl;
		

	}
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
        string s = "cabccadabaac";
        sort(s.begin(), s.end());

        cout<<s<<endl;
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}

