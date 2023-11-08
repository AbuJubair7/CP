/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 30 Jan 2022
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

 int t = 1;



 while(t--){
  
  ll a, b, n;
  cin>>a>>b>>n;
  if (b - 1 < n) {
    cout<<(a * (b - 1) / b) - (a * ((b - 1) / b))<<endl;;
  } else {
    cout<<(a * n / b) - (a * (n / b))<<endl;
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




