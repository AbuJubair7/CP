/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubair7
Date: 9 Feb 2022
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
 cin>>t;


 while(t--){
    ll n;
    cin>>n;

    vector<ll> arr(n+1);

    for(ll i = 1; i<=n; i++) cin>>arr[i];
    

    ll ans = n;

    ll l = 1;
    ll r = 1;

    while(r<=n){
        ll ind = r-l+1;
        ll sum = 0;
       
        if(arr[r] < ind){
            
            l += (ind - arr[r]);
            ind--;

            if(ind > 1){
                // inclusion
                ll N = ind-1;
                sum = (N * (N+1LL))/2LL;
                ans += sum;

                // exclusion
                ind = r-l;
                N = ind-1;
                sum = (N * (N+1LL))/2LL;
                ans -= sum;

            }

        }

        if(r == n){
            if(l != r){
                ind = r-l+1;
                ll N = ind-1;
                sum = (N * (N+1LL))/2LL;
                
                ans += sum;
           
            }
            break;
        }
        r++;
        
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




