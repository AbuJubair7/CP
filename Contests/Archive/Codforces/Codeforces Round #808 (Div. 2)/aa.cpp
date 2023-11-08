/*
Author: Jubair_7
Date: 18 July 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;


/*........................start.............................*/



void solveTwo(){
	ll t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int arr[n];

		for(int i = 0; i<n; i++) cin>>arr[i];

		vector<char> vc(m);
		for(auto &i : vc){
			i = 'B';
		}


		for(int i  = 0; i<n; i++){
			if((arr[i]) <= (m+1 - (arr[i]))){
				if(vc[arr[i]-1] == 'B'){
					vc[arr[i]-1] = 'A';
				}else vc[m-arr[i]] = 'A';
			}else{
				if(vc[m-arr[i]] == 'B'){
					vc[m-arr[i]] = 'A';
				}else vc[arr[i]-1] = 'A';
			}
		}

		for(auto i : vc)
			cout<<i;
		cout<<endl;
		vc.clear();


	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
