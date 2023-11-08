/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 27 Oct 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};

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


void sol(){
	ll t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		if(n == 1) cout<<1<<endl;
		else if(n == 2) cout<<1<<" "<<2<<endl;
		else if(n == 3) cout<<"1 2 3"<<endl;
		else if(n == 4) cout<<"3 1 4 2"<<endl;
		else{

			for(int i = 1; i<=n/2; i++){
				cout<<i+(n/2)<<" "<<i<<" ";
			}

			if(n % 2 != 0) cout<<n<<endl;
			else cout<<endl;
		}
	}
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	sol();
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}

