/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 18 Nov 2022
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
		string s;
		cin>>s;
		//transform(s.begin(), s.end(), s.begin(), ::tolower);
		int ok = 1;

		
		if(s.length() == 1){
			if(s[0] == 'Y' || s[0] == 'e' || s[0] == 's')
				ok = 1;
			else ok = 0;
		}else{
			for(int i = 1; i<s.length(); i++){

				if(s[i] == 'y'){
					ok = 0;
					break;
				}else{

					if(s[i] == 'Y' || s[i] == 'e' || s[i] == 's'){

						if(s[i] == 'Y' and s[i-1] != 's'){
							ok = 0;
							break;

						}else if(s[i] == 'e' and s[i-1] != 'Y'){
							ok = 0;
							break;
						}else if(s[i] == 's' and s[i-1] != 'e'){
							ok = 0;
							break;
						}

					}else{
						ok = 0;
						break;
					}
				}
			}


		}

		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;


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

