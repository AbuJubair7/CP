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
		vector<int> v(n);
		vector<int> result(n);
		map<int, vector<int>> mp;
	
	
		FOR(i, n){
			cin>>v[i];
			mp[v[i]].pb(i+1);
		}


		for(auto m : mp){
			int height = 1;
			int ans = height;
			//cout<<"for: "<<m.first<<endl;
			for(int i = 0; i<m.second.size()-1; i++){
				if(((m.second[i+1]-1) - m.second[i]) % 2 == 0 ||
					v[m.second[i-1]] == v[m.second[i]]){
					ans++;
					height = max(height, ans);

					//cout<<"taken: "<<endl;
				}else if(( i < m.second.size()-2
					&&((m.second[i+1]-1) - m.second[i]) == 1)
					&& v[m.second[i+2]] == v[m.second[i-1]]){
					ans++;
					height = max(height, ans);
					i++;
					//cout<<"taken: "<<endl;
				}
				else ans = 1;
				//cout<<m.second[i]<<" to "<<m.second[i+1]<<endl;
			}
			//cout<<"for: "<<m.first<<": "<<height<<endl;
			result[m.first-1] = height;
		}

		for(auto i : result)
			cout<<i<<" ";
		cout<<endl;
	

	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
