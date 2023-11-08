/*
Author: jubs
Date: 16 Aug 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;



/*........................start.............................*/



void solve(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        

        int ok = 1;
        vector<pair<ll,ll>> vc;

        for(ll i = 1; i<n; i += 2){
            ll p1 = (i+k) * (i+1);
            ll p2 = (i+1+k) * i;

            if(p1 % 4 == 0){
                vc.pb({i, i+1});
            }else if(p2 % 4 == 0){
                vc.pb({i+1, i});
            }else{
                ok = 0;
                break;
            }
        }

        if(ok){
            cout<<"YES"<<endl;
            for(auto i : vc){
                cout<<i.first<<" "<<i.second<<endl;
            }
        }else cout<<"NO"<<endl;


    }
}

int main(){
    BOOST;
    //solve();
    float x  =-0.6f;
    float x2 = x+0.1f;
    cout<<(double)abs((double)(x-0.3f) -(double) (x+0.3f))<<endl;;
    cout<<0.6 + 0.01<<endl;
    
    return 0;
}
