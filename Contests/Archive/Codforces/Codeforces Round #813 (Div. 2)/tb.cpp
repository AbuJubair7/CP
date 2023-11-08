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
    int k;
    cin>>k;
    vector<int> vc(k,0);
    for(int i = 0; i<k; i++){
        cin>>vc[i];
    }
    int line = 1;
    for(int i = 1; i<k; i++){
        if(vc[i] < vc[i-1]){
            
            line++;
        }
    }

    cout<<line<<endl;
    
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
