/*
Author: Jubair_7
Date: 8 May 2022
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
		int arr[n];
		int count = 0;
		int foundZ = 0;

		for(int i =0; i<n ;++i){
			cin>>arr[i];

			if(arr[i] == 0){
				foundZ++;
			}
		}

		// for(int i =0; i<n ;++i){
		// 	cout<<arr[i]<<" ";
		// }
		//cout<<endl;;
		int inner = 1;

		for(int i = 0; i<n && inner; i++){
			for(int j = i+1; j<n ;j++){
				if(arr[i] == arr[j]){
					//cout<<"common: "<<arr[i]<<" "<<arr[j]<<endl;
					foundZ += 2;
					count += 2;
					inner = 0;
					break;
				}
			}
		}


		if(foundZ == 0){
			count += 3;
			foundZ = 2;
			count += (n - foundZ);
		}else{
			count += (n - foundZ);
		}
		

		

		cout<<count<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
