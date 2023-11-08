/*
Author: jubs
Date: 15 Aug 2022
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
        map<ll, ll> map;
        set<ll> st;

        ll arr[n];

        FOR(i, n) {
            cin>>arr[i];
            if(map.find(arr[i]) == map.end()){
                map[arr[i]] = i;
            }
        }

        int split = -1;

        for(int i = n-1; i>0; i--){

            if(arr[i] < arr[i-1]){
                split = i-1;
                break;
            }
        }

        if(split == -1) cout<<0<<endl;
        else{

            for(int i = n-1; i>split; i--){
                if(map[arr[i]] > split)
                    st.insert(arr[i]);
                else
                    break;
            }
            // cout<<"map: "<<map.size()<<endl;
            // cout<<"set: "<<st.size()<<endl;
            // cout<<"split: "<<split<<endl;
            cout<<map.size() - st.size()<<endl;
        }
      

        
        

        
    }
}

int main(){
    BOOST;
    solve();

    
    return 0;
}
