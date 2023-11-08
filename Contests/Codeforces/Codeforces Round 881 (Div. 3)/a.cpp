/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 20 June 2023
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;



/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	//cout<<t<<endl;
	

	while(t--){
		
		int n;
		cin>>n;

		vector<int> arr(n);

		for(int i = 0; i<n; i++)
			cin>>arr[i];

		sort(arr.begin(), arr.end());

		if(n == 1) cout<<0<<endl;
		else if(n < 4) cout<<arr[n-1] - arr[0]<<endl;
		else {
			int i = 0;
			int j = n-1;
			int sum = 0;

			while(i <= j)
				sum += (arr[j--] - arr[i++]);

			cout<<sum<<endl;

		}
			
	}


	
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
        //cout<<"fsf";
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}




