/*
Author: jubs
Date: 30 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

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

bool isSorted(int arr[], int n){

	for(int i = 0; i<n-1; i++){
		
		if(arr[i] > arr[i+1]){
			return false;
		}
	}
			

	return true;
}

vector<pair<int, int>> sort(int arr[],int arr2[], int n){
	vector<pair<int, int>> v;
	int i = n-1;
	while(i > 0){

		for(int j = 0; j<=i-1; j++){
			if(arr[j] > arr[j+1] || arr2[j] > arr2[j+1]){
				swap(arr[j], arr[j+1]);
				swap(arr2[j], arr2[j+1]);
				v.pb({j+1+1,j+1 });
			}
		}
		i--;
	}

	return v;
}

bool compare(pair<int, int> p1, pair<int, int> p2){
	return p1.first < p2.first;
}

/*........................start.............................*/
void solve(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int arr2[n];

		for(int i = 0; i<n; i++) {
			cin>>arr[i];
		}
		for(int i = 0; i<n; i++) {
			cin>>arr2[i];
		}
		
		if(isSorted(arr, n) and isSorted(arr2, n)) cout<<0<<endl;
		else{
			vector<pair<int, int>> v = sort(arr, arr2, n);

			if(isSorted(arr, n) and isSorted(arr2, n)){
				cout<<v.size()<<endl;
				for(auto i : v)
					cout<<i.first<<" "<<i.second<<endl;

			}else cout<<-1<<endl;
		}

			

	

	}
}



int main(){
	BOOST;
	solve();
	
	return 0;
}

