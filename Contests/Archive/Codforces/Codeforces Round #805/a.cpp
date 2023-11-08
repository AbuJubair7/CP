/*
Author: Jubair_7
Date: 10 July 2022
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



void solveTwo(){
	ll t;
	cin>>t;
	while(t--){
		ll m;
		cin>>m;

		int p = 0;
		ll r = 0;
		ll d = 0;
		while(r < m){
			r = pow(10, p);

			if(r == m) {
				d = 0;
				break;
			}
			else if(r > m){
				
				
				p--;
				d = abs(pow(10,p) - m);
				break;
			}
			p++;
		}
		cout<<d<<endl;
	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
