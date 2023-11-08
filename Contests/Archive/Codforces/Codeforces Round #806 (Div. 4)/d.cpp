/*
Author: Jubair_7
Date: 12 July 2022
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
		int n;
		cin>>n;
		vector<string> v(n);
		map<string, int> map;

		FOR(i, n){
			cin>>v[i];
			map[v[i]]++;
		}

		FOR(i, n){
			int find = 0;
			string firstHalf = "", secondHalf = "";

			for(int j = 0; j<v[i].length(); j++){
				firstHalf += v[i][j];
				secondHalf = "";

				for(int k = j+1; k<v[i].length(); k++){
					secondHalf += v[i][k];
				}

				if(map[firstHalf] and map[secondHalf]){
					find = 1;
					break;
				}
			}

			if(find) cout<<1;
			else cout<<0;
		}
		cout<<endl;

	}
}

int main(){
	BOOST;
	solveTwo();

	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
