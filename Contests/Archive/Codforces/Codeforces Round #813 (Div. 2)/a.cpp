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
        int n, k;
        cin>>n>>k;
        int arr[n];
        map<int, int> map;
        int ans = 0;

        for(int i = 0; i<n; i++){
            cin>>arr[i];
            map[arr[i]] = i;
        }

        for(int i = 0; i<k; i++){
            
            if(arr[i] > k){
                ans++;
            }
        }

        cout<<ans<<endl;



    }
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
