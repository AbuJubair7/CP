/*............................
Author: Jubair_7
Date: 11 Oct 2022
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

// int factors[mx];

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

vector<int> allFactors(ll n){
	vector<int> fact;

	int sq = sqrt(n);

	for(int i = 1; i<=sq; i++){

		if(n % i == 0){

			if(n/i == i) {
				fact.pb(i);
			}

			else {
			
				fact.pb(i); fact.pb(n/i);
			}
		}	
	}


	return fact;

}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		
		ll n;
		cin>>n;

		vector<ll> v(n);

		ll sum = 0;

		FOR(i, n) {
			cin>>v[i];;
			sum += v[i];
		}

		vector<int> fact = allFactors(sum);
		int ok = 0;

		 ll tempSum = 0;
		

		// ..... another approch
		 sort(fact.begin(), fact.end());
		int finalLength = INT_MAX;
		

		for(auto i : fact){
			
			tempSum = 0;
			int last = 0;
			int tempLength = INT_MIN;
			ok = 0;
			// cout<<"segment change"<<endl;
			for(int j = 0; j<n; j++){
				//cout<<"v[i]: "<<<<endl;
				tempSum += v[j];
				last++;

				if(tempSum == i){
					// cout<<last<<endl;
					tempLength = max(last, tempLength);
					// cout<<"tempLength: "<<tempLength<<endl;
					last = 0;
					tempSum = 0;
					ok = 1;

				}
				else if(tempSum > i) {
					ok = 0;
					break;
				}


			}
		
			if(ok){
				
				finalLength = min(tempLength, finalLength);
			}
			
			
		}
		// cout<<endl;
		cout<<finalLength<<endl;

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

