/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 3 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5*2 + 5;



void solve(){

	int t;
	int tCase = 1;

	cin>>t;

	while(t--){
		int n, m, ans = 0;
		ll sum = 0;
		cin>>n>>m;
		priority_queue<ll> queue2;
		priority_queue<ll, vector<ll>, greater<ll>> queue;

		ll arr[n+1];

		for(int i = 0; i<n; i++) cin>>arr[i];
		int l = m;
		while(l < n){

			if(arr[l] < 0) queue.push(arr[l]);
			sum += arr[l];

			while(sum < 0){
				ll k = queue.top();
				queue.pop();
				k *= (-1) ; sum += (2*k);
				ans++;
			}
			l++;
		}

		if(arr[m-1] <= 0) sum = arr[m-1];
		else if(m != 1){
			sum = arr[m-1] * (-1);
			ans++;
		}
		l = m-2;
		while(l >= 1){
			if(arr[l] > 0) queue2.push(arr[l]);
			sum += arr[l];

			while(sum > 0){
				ll k = queue2.top();
				queue2.pop();
				k *= (-1);
				sum += (2*k);
				ans++;
			}
			l--;
		}
		cout<<ans<<endl;

	}

}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}