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
		ll n, h, m;
		cin>>n>>h>>m;
		int sleepingMin = h*60 +m;
		int timeInMin[n];
		int minitis[n];
		int hours[n];
		int presentWake = 0;


		for(int i = 0; i<n; i++){
			int hour, mini;
			cin>>hour>>mini;
			minitis[mini];
			hours[hour];

			timeInMin[i] = hour*60+mini;
			if(h == hour && mini == m) presentWake = 1;
		}

		sort(timeInMin, timeInMin+n);

		if(presentWake) cout<<0<<" "<<0<<endl;
		else{
			int minDis = INT_MAX;
			for(int i = 0; i<n; i++){
				if(timeInMin[i] >= sleepingMin){
					minDis = min(minDis , (abs(timeInMin[i] - sleepingMin)));

				}else{
					int p = (1440-sleepingMin) + timeInMin[i];
					minDis = min(minDis,p);
				}
				
			}
		
			cout<<minDis/60<<" "<<minDis%60<<endl;
		

		}
		


	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
