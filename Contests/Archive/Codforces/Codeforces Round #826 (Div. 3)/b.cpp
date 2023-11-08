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

const int mx = 1e8+123;
bitset<mx>  is_prime;
vector<int> primes;

void generatePrime(int n){
	n += 100;
	int sq = sqrt(n);

	for(int i = 3; i<=n; i+=2) is_prime[i] = 1;

	for(int i = 3; i<=sq; i+=2){
		if(is_prime[i]){

			for(int j = i*i; j<=n; j += (2*i)){
				is_prime[j] = 0;
			}
		}
	}

	primes.push_back(2);

	for(int i = 3; i<=n; i += 2){
		if(is_prime[i]) primes.push_back(i);
	}
}


vector<long long> primeFactors(long long n){

	vector<long long> factors;
	for(auto p : primes){

		if(1LL * p * p > n) break; // break if p > sqrt(n)

		if(n % p == 0){
			while(n % p == 0){
				factors.push_back(p);

				n /= p;
			}
		}
	}

	if(n > 1) factors.push_back(n);

	return factors;
}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		
		ll n;
		cin>>n;

		if(n == 3) cout<<-1<<endl;
		else if(n == 5){
			cout<<"5 4 1 2 3"<<endl;
		}
		else{

			if(n % 2 == 0){
				for(ll i = n; i>=1; i--)
					cout<<i<<" ";
				cout<<endl;
			}else{
				ll mid = (1+n)/2;
				// cout<<mid<<endl;
				for(int i = n; i>=mid+1; i--){
					if(i == mid+1){
						cout<<mid<<" ";
					}else cout<<i<<" ";
				}
				cout<<mid+1<<" ";
				for(int i = mid-1; i>=1; i--){
					cout<<i<<" ";
				}
				cout<<endl;
			}
		}
		

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

