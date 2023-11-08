/*
Author: jubs
Date: 21 July 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;

int findLowerBound(int arr[], int n, int key){
	int left = 0;
	int right = n-1;

	while(left <= right){
		int mid = (right + left)/2;

		if(arr[mid] == key || arr[mid] > key){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}

	return left;
}

/*........................start.............................*/



void solve(){
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll open = 0;
		ll close = 0;
		for(ll i = 0; i<s.length(); i++){
			if(s[i] == '(' || i == 0) open++;
			else if(s[i] == ')' || i == s.length()-1) close++;
		}

		if(s.length() == 2) cout<<"YES"<<endl;
		else{
			ll q = s.length() - (open+close);
			
			if(q == 1) cout<<"YES"<<endl;
			else{
				q -= (abs(open-close));

				if(q % 2 == 0) cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
			}
			
		}
		

	}
}

int main(){
	BOOST;
	solve();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
