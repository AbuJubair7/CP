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
		string s;
		cin>>s;
		int days = 0;
		int i = 0;

		while(i < s.length()){
			days++;
			map<char, int> map;
			int taken = 1;
			int j = i;
			while(j < s.length()){
				
				if(map[s[j]] < 1){
					if(taken <= 3){
						//cout<<s[j]<<" "<<taken<<" ";
						map[s[j]]++;
						taken++;
						i++;
					}else{
						//cout<<s[j]<<" break";
						break;
					}
				}else i++;
				j++;
			}
			//cout<<endl;
			
			map.clear();
		}

		cout<<days<<endl;


	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;


	
	return 0;
}
