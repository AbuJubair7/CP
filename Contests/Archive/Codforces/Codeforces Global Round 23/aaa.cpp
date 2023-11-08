/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: Jubair_7
Date: 16 Oct 2022
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

bool isSorted(vector<ll> v){

	if(v.size() == 1) return true;
	for(ll i = 0; i<v.size()-1; i++)
		if(v[i] > v[i+1]) return false;

	return true;
}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n;
		string s;
		cin>>n;

		int arr[n];
		char visited[n];
		map<int, vector<int>> map;

		for(int i = 0; i<n; i++){
			 cin>>arr[i];
			 map[arr[i]].pb(i);
			 visited[i] = '.';
		}

		cin>>s;

		int ok = 1;

		if(n == s.length()){
			for(int i = 0; i<n;i++){
				
				if(s[i] == visited[i] || visited[i] == '.'){
					visited[i] = s[i];
					for(auto ind : map[arr[i]]){
						visited[ind] = s[i];
					}

				}else {
					ok = 0;
					break;
				}

				// cout<<arr[i] <<" "<<arr[i+1]<<endl;;
				// cout<<s[i]<<" "<<s[i+1]<<endl; 
			}
			if(ok) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
	}else cout<<"NO"<<endl;

		

		
		
		
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

