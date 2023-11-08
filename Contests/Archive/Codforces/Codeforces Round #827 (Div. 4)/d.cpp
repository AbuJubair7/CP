/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: Jubair_7
Date: 13 Oct 2022
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
vector<pair<int, int>> pOfPrime;

void numOfPairs(){
     
    for (int i = 1; i <=1000; i++){
        for (int j = i; j <=1000; j++){

            if (__gcd(i, j) == 1){
                pOfPrime.pb({i, j});
            }
        }
    }               
}
/*........................start.............................*/
void solve(){
	numOfPairs();
	ll t;
	cin>>t;
	
	ll lastInd = 2 * 1e5 + 1;

	while(t--){
		ll n;
		cin>>n;

		ll arr[lastInd];
		memset(arr, 0, sizeof(arr));

		for(ll i = 1; i<=n; i++){
			int x;
			cin>>x;
			arr[x] = i;
		}

		ll mx = -1;

		for(auto p : pOfPrime){

			ll i, j;
			i = p.first; j = p.second;

			//cout<<i<<" "<<j<<endl;
			//cout<<arr[i]<<" "<<arr[j]<<endl;

			 if(arr[i] != 0 and arr[j] != 0) mx = max(mx, arr[i]+arr[j]);
		}

		cout<<mx<<endl;

		
	

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

