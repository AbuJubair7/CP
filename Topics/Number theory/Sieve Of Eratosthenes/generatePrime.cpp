/*
Algo: Sieve Of Eratosthenes
This is a optimized code to print all primes till n.
using bitset memory/time complexity will resuce 32 times.

*/

#include<bits/stdc++.h>
using namespace std;

const int mx = 1e8+123;

bitset<mx> primes;
vector<int> seive(int n){
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
	vector<int> p;
	p.push_back(2);

	for(int i = 3; i<=n; i += 2){
		if(primes[i] == 1){
			p.push_back(i);
		}
	}
	return p;
}

int main(){

	int lim = 1e8;
	vector<int> p = seive(lim);

	for(int i = 0; i<p.size(); i+=100){
		cout<<p[i]<<endl;
	}


}