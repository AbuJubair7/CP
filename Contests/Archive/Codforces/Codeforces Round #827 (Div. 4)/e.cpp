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

// void init(long long node, long long segTree[], int arr[], int b, int e){
// 	if(b == e){
// 		segTree[node] = arr[b];
// 		return;
// 	}
// 	init(node*2, segTree, arr, b, (b+e)/2);
// 	init(node*2+1, segTree, arr, (b+e)/2+1, e);

// 	segTree[node] = segTree[node*2] + segTree[node*2+1];

// }

// long long query(long long node, long long segTree[], int b, int e, int i, int j){
// 	if(e < i || b > j) return 0; // out of the segment

// 	if(b >= i and e <= j) return segTree[node]; // relavent segment

// 	long long left = query(node*2, segTree, b, (b+e)/2, i, j);
// 	long long right = query(node*2+1, segTree, (b+e)/2+1, e, i, j);

// 	return left+right;
// }
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n, q;
		cin>>n>>q;
		vector<ll> v(n);
		vector<ll> v2(n);
		map<ll, ll> map;

		FOR(i, n){
			ll x;
			cin>>x;
			v[i] += x;
			map[i+1] = v[i];
			v2[i] = v[i];
		}

		for(int i = 1; i<n; i++){
			v2[i] += v2[i-1];
			v[i] = max(v[i], v[i-1]);
		}

		// for(auto i : v) cout<<i<<" ";
		// cout<<endl;

		for(int i = 0; i<q; i++){
			ll k;
			cin>>k;
			if(k == 0) cout<<0<<" ";
			else if(k >= v2[v2.size()-1]) cout<<v2[v2.size()-1]<<" ";
			else if(k < v2[0]) cout<<0<<" ";
			else{
				vector<ll>::iterator upper = upper_bound(v.begin(), v.end(), k);
				cout<<v2[(upper - v.begin())-1]<<" ";

				//cout<<"upper of "<<k<<" is: "<<v2[(upper - v.begin())-1]<<endl;
			}

			

		}

		cout<<endl;


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

