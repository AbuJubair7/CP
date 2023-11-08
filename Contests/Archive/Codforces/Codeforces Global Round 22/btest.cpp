/*............................
Author: jubs
Date: 30 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

 int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
 int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

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

/*........................start.............................*/
void solve(){
    ll t;
    cin>>t;

    while(t--){
        ll n, k;
        cin>>n>>k;

        ll arr[k+1];
        int ok = 1;

        for(ll i = 0; i<k; i++) cin>>arr[i];

        if(k == 1 || n == 1) cout<<"YES"<<endl;
        else if(n == k){
            ll dis = arr[0];
            for(int i = 0; i<n-1 and ok; i++){
                if(arr[i+1] - arr[i] >= dis) dis = arr[i+1] - arr[i];
                else ok = 0;
                
            }

            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            ll dis = arr[1]-arr[0];

            if(dis * k >= arr[0]){
                for(ll i = 1; i<k-1 and ok; i++){

                    if(arr[i+1] - arr[i] >= dis) dis = arr[i+1]-arr[i];
                    else ok = 0;
                }

                if(ok) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else cout<<"NO"<<endl;

        }
    }
}

int main(){
    BOOST;
    solve();

    //cout<<abs(abs(-3) - abs(0))<<endl;

    return 0;
}

