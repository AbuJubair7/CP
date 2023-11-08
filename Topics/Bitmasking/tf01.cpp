#include<bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int find = 0;
		for(int i = 0; i<n; i++)cin>>arr[i];

		long k = 0;
		cin>>k;
		int tot = 1<<n;
		for(int i = 0; i<tot; i++){
			long sum = 0;

			for(int j = 0; j<n; j++){
				int bit = 1<<j;

				if(bit & i){
					sum += (arr[j]);
				}
			}
			if(sum == k){
				find =1;
				break;
			}
		}
		if(find) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
	



	return 0;
}