/*
Author: jubair7
Date: 11 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;
const int mx = 1e8+123;
bitset<mx> primes;


void seive(int n){
	n += 100;
	int sq = sqrt(n);
	for(int i = 3; i<=n; i+=2) primes[i] = 1;
	for(int i = 3; i<=sq; i+=2){
		if(primes[i] == 1){
			for(int j = i * i; j<=n; j += (i+i)){
				primes[j] = 0;
			}
		}
	}
	primes[2] = 1;
}

void solve(){
	int t;
	cin>>t;
	int lim = (1e5 * 2);
	seive(lim);
	while(t--){
		int n;
		cin >> n;
		vector<int> primesLeft, innerLeft, primesRight, innerRight;
		if(n == 1) cout << 1 << '\n';
		else if(n == 2) cout << "2 1" << '\n';
		else if(n == 3) cout << "2 1 3" << '\n';
		else{
			int left = 1;
			for(int i = 2; i<=n; i++){
				if(primes[i]){
					if(left){
						primesLeft.push_back(i);
						left = 0;
					}else{
						primesRight.push_back(i);
						left = 1;
					}
				}else{
					if(left){
						innerLeft.push_back(i);
						left = 0;
					}else{
						innerRight.push_back(i);
						left = 1;
					}
				}
			}
			reverse(innerLeft.begin(), innerLeft.end());
			reverse(primesLeft.begin(), primesLeft.end());
			for(auto i : primesLeft) cout << i << " ";
			for(auto i : innerLeft) cout << i << " ";
			cout << 1 << " ";
			for(auto i : innerRight) cout << i << " ";
			for(auto i : primesRight) cout << i << " ";
			cout << '\n';
		}
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}