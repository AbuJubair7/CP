/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubair7
Date: 3 Feb 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back


typedef long long ll;
const int mx = 1e5  + 1;
bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}
/*........................start.............................*/
void solve(){

 int t;
 cin>>t;


 while(t--){
  int n, c;
  cin>>n>>c;
  vector<int> arr(n);
  vector<int> v;
  for(int i = 0; i<n; i++) cin>>arr[i];
  for(int i = 0; i<n; i++){
    v.pb(arr[i]+i+1);
  }
  sort(v.begin(), v.end());
  int ans = 0;
  int lastTelePot = 0;
  for(int i = 0; i<n; i++){
    if(v[i] <= c){
        c -= (v[i]);

        ans++;
    }
  }

  cout<<ans<<endl;

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



