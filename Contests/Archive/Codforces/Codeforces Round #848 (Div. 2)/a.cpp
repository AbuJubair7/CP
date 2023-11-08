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

/*........................start.............................*/
void solve(){

 int t;
 cin>>t;


 while(t--){
  int n;
  cin>>n;
  vector<int> arr(n);
  int haveNeg = 0;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
    if(arr[i] < 0) haveNeg = 1;
  }
  int ok = 0;
  for(int i = 0; i<n-1; i++){
    if(arr[i] < 0 and arr[i+1] < 0){
        arr[i]  = 1;
        arr[i+1] = 1;
        ok = 1;
        break;
    }
  }

  if(ok){
    int ans = 0;
    for(auto i : arr){
        ans += (i);
    }
    cout<<ans<<endl;
  }else{
    int ans = 0;
    if(haveNeg){
        for(auto i : arr){
            ans += (i);
        }
        cout<<ans<<endl;
    }else{
        arr[0] = -1;
        arr[1] = -1;
        for(auto i : arr){
            ans += (i);
        }
        cout<<ans<<endl;
    }
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




