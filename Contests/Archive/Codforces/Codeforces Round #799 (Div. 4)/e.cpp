/*
Author: Jubair_7
Date: 16 June 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
	return (a*b)/gcd(a,b);
}

int foundUpper(vector<int> vc,int l, int point){
	int left = l;
	int right = vc.size()-1;

	while(left <= right){
		int mid = (left+right)/2;

		if(vc[mid] == point){
			left = mid+1;
		}else if(vc[mid] > point) right = mid-1;
		else left = mid+1;
	}

	return right;
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		int n, s;
		cin>>n>>s;
		int len = 0;
		int sum = 0;
		
		vector<int> vc(n);
		

		FOR(i, n){
			cin>>vc[i];
			sum += vc[i];
		}

		if(sum <  s) cout<<-1<<endl;
		else if(sum == s) cout<<0<<endl;
		else{
			int leftInd = 0;
			int index = 0;
			int cnt = 0;
			int ans = 0;
			int j = 0;
			

			for(int i = 0; i<n; i++){
				ans += vc[i];
				cnt++;
				
				if(ans == s) {
					index = i;
					break;
				}
			}
			int mxLen = cnt;
			for(int i = index+1; i<n; i++){
				j = i;

				while(j<n){
					if(vc[j] == 1){
						break;
					}
					cnt++;
					j++;
					mxLen = max(mxLen, cnt);
				}
				i = j;

				while(leftInd < n){
					if(vc[leftInd] == 1){
						leftInd++;
						break;

					}
					cnt--;
					leftInd++;
					mxLen = max(mxLen, cnt);
				}

			}
			cout<<n-mxLen<<endl;

			
		}

		
			
	}





		
     
}

int main(){
	BOOST;
	solve();

	return 0;
}
