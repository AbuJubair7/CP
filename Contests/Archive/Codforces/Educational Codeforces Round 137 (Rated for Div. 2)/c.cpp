/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 17 Oct 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

// const int mx = 1e8+123;
// bitset<mx>  is_prime;
// vector<int> primes;

// void generatePrime(int n){
// 	n += 100;
// 	int sq = sqrt(n);

// 	for(int i = 3; i<=n; i+=2) is_prime[i] = 1;

// 	for(int i = 3; i<=sq; i+=2){
// 		if(is_prime[i]){

// 			for(int j = i*i; j<=n; j += (2*i)){
// 				is_prime[j] = 0;
// 			}
// 		}
// 	}

// 	primes.push_back(2);

// 	for(int i = 3; i<=n; i += 2){
// 		if(is_prime[i]) primes.push_back(i);
// 	}
// }


// vector<long long> primeFactors(long long n){

// 	vector<long long> factors;
// 	for(auto p : primes){

// 		if(1LL * p * p > n) break; // break if p > sqrt(n)

// 		if(n % p == 0){
// 			while(n % p == 0){
// 				factors.push_back(p);

// 				n /= p;
// 			}
// 		}
// 	}

// 	if(n > 1) factors.push_back(n);

// 	return factors;
// }
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		char lids[n];
		int maga[n];
		vector<vector<int>> vecArr;

		for(int i = 0; i<n; i++) cin>>lids[i];

		for(int i = 0; i<n; i++) cin>>maga[i];

		int min = maga[0];
		int minIndex = 0;

		for(int i = 0; i<n; i++){

			if(lids[i] == '1'){

				if(min > maga[i] and lids[minIndex] != '1'){
					//cout<<"here"<<endl;
					lids[i] = '0';
					lids[minIndex] = '1';
					min = maga[i];
					minIndex = i;
				}
			}else{
				min = maga[i];
				minIndex = i;
			}

		}


		ll sum = 0;
		for(int i = 0; i<n; i++){
			//cout<<lids[i]<<" ";
			if(lids[i] == '1') sum += maga[i];
		}
		cout<<endl;
		cout<<sum<<endl;
	}
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}

