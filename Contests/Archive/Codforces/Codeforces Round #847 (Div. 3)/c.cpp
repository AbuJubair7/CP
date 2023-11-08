/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 27 Jan 2022
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


/*........................start.............................*/
void solve(){

 int t;
 cin>>t;
 vector<int> arr[6];
 arr[0] = {1, 2, 3};
 arr[1] = {1, 3, 2};
 arr[2] = {2, 1, 3};
 arr[3] = {2, 3, 1};
 arr[4] = {3, 1, 2};
 arr[5] = {3, 2, 1};

 vector<pair<int, int>> st[6];
 st[0].pb ( {2,3});
 st[0].pb ( {1,3});
 st[0].pb ( {1,2});

 st[1].pb ({3,2});
 st[1].pb ( {1,3});
 st[1].pb ({1,2});

 st[2].pb ({2,3});
 st[2].pb ({1,3});
 st[2].pb ({2,1});

 st[3].pb ( {2,3});
 st[3].pb ({3,1});
 st[3].pb ( {2,1});

 st[4].pb ({3,2});
 st[4].pb ( {3,1});
 st[4].pb ( {1,2});

 st[5].pb({3,2});
 st[5].pb({3,1});
 st[5].pb({2,1});

 while(t--){
  int n;
  cin>>n;
	  
	  
  // restart query
  if(n > 3){
	map<int, int> map;
	  vector<int> p;
	  int missing = 0;
	  int q = 2;
	  for(int i = 1; i<n; i++){
	  	int x;
	  	cin>>x;
	  	p.pb(x);
	  	map[x]++;
	  }
	 
	  // taking missing item
	  for(int i = 1; i<=n; i++){
	  	if(map[i] == 0){
	  		missing = i;
	  		break;
	  	}
	  }
	  // restart query
	  map.clear();
	  vector<int> tmp(n-1);
	  while(q <= n){
	  	for(int i = 0; i<n-1; i++){
	  		cin>>tmp[i];
	  		if(tmp[i] == missing){
	  			if(i == 0){
	  				map[0]++;
	  			}else map[tmp[i-1]]++;
	  		}
	  	}
	  	q++;
	  }
	  int frontItem = 0;
	  int maxAppear = INT_MIN;
	 
	  for(auto i : map){
	  	if(i.second > maxAppear){
	  		frontItem = i.first;
	  		maxAppear = i.second;
	  	}
	  }
	 
	  if(frontItem == 0){
	  	 cout<<missing<<" ";
	  	 for(auto i : p) cout<<i<<" ";
	  }else{
	  	for(auto i : p){
	  		if(i == frontItem){
	  			cout<<i<<" "<<missing<<" ";
	  		}else cout<<i<<" ";
	  	}
	  }
	}else{
		vector<pair<int, int>> tmp;
		int q = 3;

		while(q--){
			int a, b;
			cin>>a>>b;
			tmp.pb({a,b});
		}
		int ind = 0;
		for(int i = 0; i<6; i++){
			int innerOk = 0;
			
			for(int j = 0; j<3; j++){
				
				pair<int, int> k = tmp[j];
				for(int p = 0; p<st[i].size(); p++){
					
					if(st[i][p].first == k.first and st[i][p].second == k.second){
						
						innerOk = 1;
						break;
					}else innerOk = 0;
				}
				if(!innerOk) break;
			}

			if(innerOk){
				ind = i;
				break;
			}
		}
		for(int i = 0; i<3; i++){
			cout<<arr[ind][i]<<" ";
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




