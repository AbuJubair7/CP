/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 21 Oct 2022
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
void solve(){
	ll t;
	cin>>t;

	while(t--){
		int n, m;
		cin>>n>>m;


		unordered_map<int, bool> posX;
		unordered_map<int, bool> posY;
		vector<pair<int, int>> set;

		for(int i = 0; i<m; i++){
			int x, y;
			cin>>x>>y;

			posX[x] = 1;
			posY[y] = 1;
			set.pb({x, y});
			//cout<<"booked: "<<x<<" "<<y<<endl;
		}

		int ok = 0;

		for(auto i : set){

			ok = 1;
			int x = i.first;
			int y = i.second;
			//cout<<"given: "<<x<<" "<<y<<endl;
			//cout<<pos[x+1]<<endl;
			if(x+1 <=n and posX[x+1] != 1) break;
			if(x-1 >=1 and posX[x-1] != 1) break;
			if(y+1 <=n and posY[y+1] != 1) break;
			if(y-1 >=1 and posY[y-1] != 1) break;
			
			ok = 0;

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

