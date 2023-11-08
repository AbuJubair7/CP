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
const int mx = 1e5  + 1;

const static string PI = "3141592653589793238462643383279";

/*........................start.............................*/
void solve(){

 int t = 1;
 cin>>t;


 while(t--){
   int n;
   cin>>n;
   vector<int> arr(n);
   int twoCnt = 0;
   int oneCnt = 0;
   for(int i = 0; i<n; i++){
    cin>>arr[i];
    if(arr[i] == 1) oneCnt++;
    else twoCnt++;
   }


   if(twoCnt == 0) cout<<1<<endl;
   else if(twoCnt % 2) cout<<-1<<endl;
   else{
    int point = twoCnt/2;
    int ans= 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == 2) point--;
        if(point == 0){
            ans = i+1;
            break;
        }
    }
    cout<<ans<<endl;
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




