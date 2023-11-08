/*
Derangement
formula: n! * (1- nC1 * (n-1)! + nC2 - nC2 * (n-2)! + ...+..-.. - nCn * (n-n)!)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fact(ll n){
    ll f = 1;
    for(ll i = 2; i<=n; i++)
        f *= i;
    return f;
}


ll nCr(int n, int r){
    return (fact(n) / (fact(r) * fact(n-r)));
}

ll derangment(int n){
    ll dN = fact(n);

     
    int plus = 1;

    for(int i = 1; i<=n; i++){
        ll sum = nCr(n, i) * fact(n-i);
        if(plus){
            dN -= sum;
            plus = 0;
        }else{
            dN += sum;
            plus = 1;
        }
    }

   return dN;
}

int main(){
    ll n,m;

   while(cin>>n>>m){
     ll ans = derangment(n);

     for(int i = 1; i<=m; i++){
        ans += (nCr(n, i) * derangment(n-i));
     }
     cout<<ans<<endl;
   }

    
    return 0;
}