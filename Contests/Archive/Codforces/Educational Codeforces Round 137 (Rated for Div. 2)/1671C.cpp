/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 19 Oct 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
// #define jubs

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

ll fact(int n){
	ll sum = 1;

	for(int i = n; i >=1; i--){
		sum *= i;
	}

	return sum;
}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n, x;
		cin>>n>>x;

		vector<ll> arr(n+1);
		vector<ll> rangeSum(n+1);

		ll l = 1;
		ll r = n-1;
		int canBuy = 0;

		int sum = 0;

		for(int i = 1; i<=n; i++) {
			cin>>arr[i];
			
		}

		sort(arr.begin(), arr.end());

		for(int i = 1; i<=n; i++){
			sum += arr[i];
			if(sum <= x){
				rangeSum[i] = sum;
				r = i;
				canBuy++;
			}else break;
		}

		ll day = 0;
		ll ans = 0;


		if(canBuy){
			for(int i = r; i>=1; i--){
				if(rangeSum[i] <= x){
					day = ((x -rangeSum[i])/i);
					//cout<<"diff for "<<rangeSum[i]<<": "<<x-rangeSum[i]<<endl;
					//cout<<"range sum: "<<rangeSum[i]<<endl;
					//cout<<rangeSum[i]<<" can be get: "<<day+1<<"'s"<<endl;
					ans += (day+1 );
				}
			}
		}


		cout<<ans<<endl;


		

	}
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
        // cout<<ceil(2.0/3.0)<<endl;
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}

