/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubair7
Date: 3 Feb 2022
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

/*........................start.............................*/
void solve(){

 int t;
 cin>>t;


 while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    int negCount = 0;
    ll sum= 0;
    for(int i = 0; i<n; i++){
         cin>>arr[i];
         if(arr[i] < 0) negCount++;
         sum += abs(arr[i]);
    }

    if(negCount % 2 == 0){
        cout<<sum<<endl;
    }else{
        int minEle = INT_MAX;
        
        for(int i = 0; i<n; i++){
            minEle = min(minEle, abs(arr[i]) );
           
        }
       cout<<sum - 2 * minEle<<endl;
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
