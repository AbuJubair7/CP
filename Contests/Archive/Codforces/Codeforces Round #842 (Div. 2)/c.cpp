/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 5 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5*2 + 5;


void solve(){

	int t;
	int tCase = 1;

	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		vector<int> v1(n+1, -1);
		vector<int> v2(n+1, (-1));
		vector<int> p1(n);
		vector<int> p2(n);
		set<int> set1, set2;


		int ok = 1;

		for(int i = 0; i<n; i++){
			cin>>arr[i];
		}


		for(int i = 0; i<n; i++){

			if(v1[arr[i]] == -1){
				v1[arr[i]] = i;
				p1[i] = arr[i];

			}else if(v2[arr[i]] == -1){
				v2[arr[i]] = i;
				p2[i] = arr[i];
			}else{
				ok = 0;
				break;
			}
		}

		if(!ok) cout<<"No"<<endl;
		else{
			for(int i = 1; i<=n; i++){
				if(v1[i] == -1 ) set1.insert(i);
				if(v2[i] == -1) set2.insert(i);
			}

			for(int i = 0; i<n; i++){
				if(p1[i] == 0){
					auto it = set1.upper_bound(p2[i]);

					if(it == set1.begin()){
						ok = 0;
						break;
					}else{
						it--;
						p1[i] = *it;
						set1.erase(it);
					}

				}else{
					auto it = set2.upper_bound(p1[i]);

					if(it == set2.begin()){
						ok = 0;
						break;
					}else{
						it--;
						p2[i] = *it;
						set2.erase(it);
					}

				}
			}

			if(ok){
				cout<<"Yes"<<endl;
				for(int i = 0; i<n; i++) cout<<p1[i]<<" ";
				cout<<endl;
				for(int i = 0; i<n; i++) cout<<p2[i]<<" ";
				cout<<endl;
			}else cout<<"No"<<endl;
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