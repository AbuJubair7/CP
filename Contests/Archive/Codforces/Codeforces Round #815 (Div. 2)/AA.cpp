/*
Author: jubs
Date: 20 Aug 2022
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
        ll m, n;
        cin>>n>>m;

        if(n == 1 && m == 1) cout<<0<<endl;
        else if(n == 1) cout<<m-1 + n<<endl;
        else if(m == 1) cout<<n-1 + m<<endl;
        else{
            n--; m--;
            cout<<(n+m) + min(n,m)+1<<endl;
        }



    }
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
