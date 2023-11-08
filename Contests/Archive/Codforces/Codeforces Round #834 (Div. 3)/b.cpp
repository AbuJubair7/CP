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
		int m, s;
		cin>>m>>s;

		vector<int> v;
		map<int, int> map;

		int ok = 1;

		for(int i = 0; i<m; i++){
			int x;
			cin>>x;

			v.pb(x);
			map[x]++;

			if(map[x] > 1) ok = 0;
			
		}

		if(ok){
			int sum = 0;
			sort(v.begin(), v.end());

			// int arr[v[v.size()-1]+1];
			// memset(arr, 0, sizeof(arr));

			for(int i = 1; i<=v[v.size()-1]; i++){

				if(map[i] != 1) {
					sum += i;
					//cout<<"Missing: "<<i<<endl;
				}
				
			}

			if(sum > s) cout<<"NO"<<endl;
			else if(sum == s) cout<<"YES"<<endl;
			else{
				int i = v[v.size()-1]+1;

				while(sum < s){
					sum += i;
					//cout<<"extra: "<<i<<endl;
					i++;
				}

				if(sum == s) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}

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

