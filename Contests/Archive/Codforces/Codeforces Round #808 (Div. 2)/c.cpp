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
		cin >> n;
		vector<ll> a(n);
		for(ll i =0; i<n; i++) cin >> a[i];
		if (n % 2){
	    int ans = 0;

	    for (int i = 1; i < n - 1; i += 2){
	        ans += max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0LL);
	    }

	    cout << ans << endl;

		}else{

	    int ans = 0, ans1 = 0;

	    vector<ll> pref(n / 2), pref2(n / 2);
	    int j = 1;

	    for (int i = 1; i < n - 1; i += 2) {
	        int res = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0LL);
	        pref[j] = pref[j - 1] + res;
	        j++;
	    }
	    j = 1;
	    for (int i = 2; i < n - 1; i += 2){
	        int res = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0LL);
	        pref2[j] = pref2[j - 1] + res;
	        j++;
	    }



	    ans = INT_MAX;

	    for (int i = 0; i < n / 2; i++){
	        
	        if(ans < (pref[i] + pref2[n / 2 - 1] - pref2[i])) ans = ans;
	        else ans = pref[i] + pref2[n / 2 - 1] - pref2[i];
	    }
	    cout << ans << endl;
		

		}
	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}

