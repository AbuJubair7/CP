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
    int n;
    cin>>n;

    if(n == 2) cout<<"Odd"<<endl;
    else if(n == 1 || n == 3) cout<<"Either"<<endl;
    else if(n % 2 == 0) {
        if((n/2) % 2 == 0) cout<<"Even"<<endl;
        else cout<<"Odd"<<endl;
    }
    else cout<<"Either"<<endl;
    
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
