#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;
using namespace std;


int main(){

	int n;
	cin>>n;

	ll sum = (n * (n+1ll))/2ll;

	if(sum % 2) cout<<"NO"<<endl;
	else{

		ll mid = sum/2;
		ll tmp = 0;


	
		vector<int> st1;
		vector<int> st2;


		for(int i = n; i>=1; i--){
			if(tmp + i <= mid){
				tmp += i;
				st1.pb(i);
			}else{
				st2.pb(i);
			}
		}

		if(tmp == mid){
			cout<<"YES ";
			cout<<st1.size()<<" ";

			for(auto i : st1) cout<<i<<" ";

			cout<<st2.size()<<" ";

			for(auto i : st2) cout<<i<<" ";
		}


	}


	return 0;
}