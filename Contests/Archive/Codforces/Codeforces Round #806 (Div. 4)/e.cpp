/*
Author: Jubair_7
Date: 12 July 2022

Approch:
The approch is to go circle wise ove the grid by selecting each layer.
Every iteration check for ones and zeros and select the minimum and add
that with the ans.
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
		int n;
		cin>>n;

		char arr[n][n];
		char roateArr[n][n];
		for(int row = 0; row<n; row++){
			for(int col = 0; col<n; col++){
				cin>>arr[row][col];
			}
		}
	
		// check
		int ans = 0;
		int layer = n/2;

		int i = 0;
		int checkPoint = n-1;
		int r1 = 0;
		int r2 = n-1;
		int c1 = 0;
		int c2 = n-1;

		int tr1 = r1;
		int tr2 = r2;
		int tc1 = c1;
		int tc2 = c2;
	

		int zero = 0;
		int one = 0;

		while(i < layer){
			tr1 = r1;
			tr2 = r2;
			tc1 = c1;
			tc2 = c2;

			//cout<<"layer: "<<i+1<<endl;
			for(int j = 0; j<checkPoint; j++){
				one = 0;
				zero = 0;
				if(arr[r1][tc1++] == '0') zero++;
				else one++;

				if(arr[tr1++][c2] == '0') zero++;
				else one++;

				if(arr[r2][tc2--] == '0') zero++;
				else one++;

				if(arr[tr2--][c1] == '0') zero++;
				else one++;

				ans += min(4-one, 4-zero);
				//cout<<arr[r1][tc1++]<<" "<<arr[tr1++][c2]<<" "<<arr[r2][tc2--]<<" "<<arr[tr2--][c1]<<endl;
				//cout<<r1<<","<<tc1++<<" "<<tr1++<<","<<c2<<" "<<r2<<","<<tc2--<<" "<<tr2--<<","<<c1<<endl;

			}
		
			r1++;
			c1++;
			r2--;
			c2--;
			checkPoint -= 2; // every layer decrease the values by two (both from left and right) 
			i++;
		}
		

		

		
		cout<<ans<<endl;



	}
}

int main(){
	BOOST;
	solve();
	
	return 0;
}
