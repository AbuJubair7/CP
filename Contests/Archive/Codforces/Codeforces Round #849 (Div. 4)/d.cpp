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
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;

/*........................start.............................*/
void solve(){

 int t;
 cin>>t;


 while(t--){
  ll n;
  cin>>n;
  string s;
  cin>>s;

  map<char, int> m1, m2;
  vector<int> v1(n,0), v2(n,0);

  for(int i = 0; i<n; i++){
    m1[s[i]]++;
    if(m1[s[i]] == 1){
        if(i == 0) v1[i] = 1;
        else
            v1[i] = v1[i-1]+1;
       // cout<<"v1: "<<v1[i]<<endl;
    }else v1[i] = v1[i-1];
  }

  for(int i = n-1; i>=0; i--){
    m2[s[i]]++;
    if(m2[s[i]] == 1){
         if(i == n-1) v2[i] = 1;
         else
            v2[i] = v2[i+1]+1;
    }else v2[i] = v2[i+1];
  }

  int ans = INT_MIN;
  for(int i = 0; i<n-1; i++){
    ans = max(ans, v1[i]+v2[i+1]);
   
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




