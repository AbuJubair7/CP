
#include <bits/stdc++.h>
using namespace std;


int main(){

	long long t;
	cin>>t;

	while(t--){
	long long  n;
		cin>>n;
	long long  arr[n];

		for(long long i = 0; i<n; i++) cin>>arr[i];
		int even = 0;
		int odd = 0;

		for(long long i = 0; i<n; i++){
			if(arr[i] % 2 == 0) even++;
			else odd++;
		}
				
		cout<<min(even, odd)<<endl;
	}
	return 0;
}
