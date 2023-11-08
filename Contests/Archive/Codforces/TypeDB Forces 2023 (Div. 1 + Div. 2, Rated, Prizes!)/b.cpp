/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 29 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;

const static string PI = "3141592653589793238462643383279";
    
bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}
void primeFactors(ll num) { 


    map<int, int> map;
    for(int i=2; i<=sqrt(num); i++){
        int cnt = 0;
        while(num % i == 0) {
            cnt++;
            num/=i;
        }
        map[i] = cnt;
    }
    if(num != 1){
         map[num] = 1;
    }
    vector<pair<int, int>> v;

    for(auto i : map){
        v.pb(i);
    }

    sort(v.begin(), v.end(), cmp);
    
    int i = 0;
    ll ans = 0;
    while(i < v.size()){

        if(v[i].second >= 2){
            ll facts = 1;
            facts *= v[i].first;
            v[i].second -= 2;
            for(int j = i+1; j<v.size(); j++){
                v[j].second -= 2;
                facts *= v[j].first;
            }
            
            ans += (facts*2);
        }else{
            if(v[i].second > 0){
                ll facts = 1;
                facts *= v[i].first;
                v[i].second -= 1;
                for(int j = i+1; j<v.size(); j++){
                    v[j].second -= 1;
                    facts *= v[j].first;
                }
                
                ans += facts;
                
            }
            i++;
        }
    }

 
    cout<<ans<<endl;
}

/*........................start.............................*/
void solve(){

 int t;
 cin>>t;


 while(t--){
  int n;
  cin>>n;
  primeFactors(n);
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




