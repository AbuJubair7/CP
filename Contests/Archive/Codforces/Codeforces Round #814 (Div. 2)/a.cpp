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
        ll n, m;
        cin>>n>>m;

        if(n == 1 && m == 1){
            cout<<"Tonya"<<endl;
        }else if(n == 1){
            if(m % 2 == 0){
                cout<<"Burenka"<<endl;
            }else cout<<"Tonya"<<endl;
        }else if(m == 1){
            if(n % 2 == 0){
                cout<<"Burenka"<<endl;
            }else cout<<"Tonya"<<endl;

        }else{
            if(n % 2 == 0 && m%2 != 0){
                cout<<"Burenka"<<endl;
            }else if(n % 2 == 0 && m % 2 == 0){
                cout<<"Tonya"<<endl;
            }else if(n % 2 != 0 && m%2 == 0){
                cout<<"Burenka"<<endl;
            }else{
                cout<<"Tonya"<<endl;
            }
        }


    }
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
