/*............................
Author: jubs
Date: 29 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

 int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
 int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

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

		int row = 0, col = 0;
		int isolated = 0;

		for(int i = 0; i<n; i++){

			for(int j = 0; j<m; j++){
				isolated = 1;
				for (int k = 0; k < 8; k++) {
			      
			        int x = i + X[k];
			        int y = j + Y[k];
			   
			        if (x >= 0 && y >= 0 && x < n && y < m){
			        	isolated = 0;
			        	break;
			        }
			            
			    }
			    if(isolated){
			    	isolated = 1;
		        	row = i+1;
		        	col = j+1;
			        break;
			    }
			}

			if(isolated){
				break;
			}
		}

		if(isolated) cout<<row<<" "<<col<<endl;
		else cout<<1<<" "<<1<<endl;
		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

