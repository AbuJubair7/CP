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

/*........................start.............................*/
void solve(){

 int t;
 cin>>t;

 while(t--){
  int n;
  cin>>n;
  vector<int> arr2;
  map<int, int> m;
  for(int i = 0; i<n; i++){
    int x;
    cin>>x;
    m[x]++;
    if(m[x] == 1) arr2.pb(x);
  }
  
  sort(arr2.begin(), arr2.end());

  int ans = 1;
  int x = arr2[0];
  for(auto i : arr2){
    if(i > x+1){

        ans++;
       
    }
    x = i;
    m[x]--;
  }
  
  for(int i = 0; i<arr2.size(); i++){
    int val = arr2[i];
    
    if(m[val] > 0){
       
        ans += m[val];
        int decreaseVal = m[val];
        int incr = 1;
        int check = val+1;
        for(int j = i+1; j<arr2.size(); j++){
            
            if(arr2[j] == check and m[arr2[j]] > 0){
                
                int dis = abs(m[check]-m[val]);
              
                int tmp = m[check];
                m[check] -= decreaseVal;
                if(m[check] <= 0)
                    decreaseVal = tmp;
                
               
            }else break;
            check++;
        }
        m[val] = 0;
    }
  }
  cout<<ans<<endl;
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




