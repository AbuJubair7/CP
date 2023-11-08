/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubair7
Date: 2 Feb 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;

const static string PI = "3141592653589793238462643383279";

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
	return p1.first < p2.first;
}

/*........................start.............................*/
void solve(){

 int t;
 cin>>t;


 while(t--){
  int n, k;
  cin>>n>>k;
  string a, b;
  cin>>a>>b;

  if(k == 0){

  }else{
  	vector<pair<int, pair<int, int>>> p;
  	int ind = 0;
  	while(ind<n){
  		int l = ind;
  		int r = ind;

	  	if(a[l] != b[r]){
	  		int j = ind+1;
	  		while(j<n){
	  			
	  			if(a[j] == b[j]){
	  				break;
	  			}else r++;
	  			
	  			j++;
	  			ind = j;
	  		}
	  		int range = (r-l)+1;
	  		p.pb({range, {l, r} });
	  	}
  		ind++;
  	}

  	sort(p.begin(), p.end(), cmp);
  	map<char, int> frq;
  	for(auto i : p){
  		if(k<=0) break;
  		if(i.second.first == 0){
  			for(int j = i.second.second; j>=i.second.first; j--){
  				frq[a[j]]++;
  				if(frq[a[j]] == 1) k--;
  				
  				if(k >= 0) a[j] = b[j];
  				else break;
  			}
  		}else{
  			for(int j = i.second.first; j<=i.second.second; j++){
  				frq[a[j]]++;
  				if(frq[a[j]] == 1) k--;
  				
  				if(k >= 0) a[j] = b[j];
  				else break;
  			}
  		}
  	}

  	// counting pair
  	for(auto i : p){
  		cout<<i.first<<endl;
  	}
  	ll ans = 0;
  	ind = 0;
  	while(ind<n){
  		int l = ind;
  		int r = ind;
	  	ll sum = 0;
	  	if(a[l] == b[r]){
	  		int j = ind+1;
	  		while(j<n){
	  			
	  			if(a[j] != b[j]){
	  				break;
	  			}else r++;
	  			
	  			j++;
	  			ind = j;
	  		}
	  		int range = (r-l)+1;
	  		sum = (range * (range+1)) / 2;
	  		
	  	}

  		ans += sum;
  		ind++;
  	}

  	//cout<<ans<<endl;

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




