/*
Author: jubs
Date: 13 Aug 2022
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
        ll n;
        cin>>n;
        ll arr[n];
        FOR(i, n){
            arr[i] = i+1;
        }
        for(int i = n-1; i>=1; i -= 2){
            swap(arr[i], arr[i-1]);
        }

        FOR(i, n) cout<<arr[i]<<" ";
        cout<<endl;


    }
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
