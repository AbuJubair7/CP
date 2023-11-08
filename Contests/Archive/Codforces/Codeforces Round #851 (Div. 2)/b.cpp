/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubair7
Date: 9 Feb 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const ll mx = 1e9  + 1;
static vector<ll> d(mx);

const static string PI = "3141592653589793238462643383279";

ll getSum(int n){
    string s = to_string(n);
    int sum = 0;
    for(int i= 0; i<s.length(); i++){
        sum += (s[i]-'0');
    }

    return sum;
}

// void build(){
//     for(int i = 11; i<mx; i += 2){
//         ll div = i/2;
//      while(abs(getSum(div) - getSum(i-div)) > 1){
//              div++;
//         }
//         d[i] = div;;
//     }
// }

/*........................start.............................*/
void solve(){
// build();
 int t = 1;
 cin>>t;


 while(t--){
  ll n;
  cin>>n;
  string s = to_string(n);



 if(n % 2){
    ll div = n/2;
    ll div2 = n-div;
    string tmp = to_string(n);
    int a = 0;
    int b = 0;
    int cnt = 0;
    for(int i = tmp.length()-1; i >= 0; i--){
        if(tmp[i] == '9'){
            a += 4;
            b += 5;

        }else break;
        a *= (cnt*10);
        b *= (10 * cnt);
        cnt++;
    }

    // if(n < 10){
    //     cout<<n/2<<" "<<n/2+1<<endl;

    // }else cout<<d[n]<<endl;
  
    cout<<div+a<<" "<<div2-a<<endl;
    cout<<div<<" "<<div2<<endl;
    
  }
   else{
    cout<<n/2<<" "<<n/2<<endl;
  }

 }



 
    
}

int main(){
    BOOST;
    #ifdef jubs
        double start = clock();
    #endif

    solve();
    
    #ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
    return 0;
}




