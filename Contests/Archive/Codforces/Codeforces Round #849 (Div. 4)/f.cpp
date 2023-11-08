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
const int mx = 1e5 * 2  + 2;
const int root = sqrt(mx);
ll arr[mx];
ll value[mx];

void build(int n){
  int sqr = sqrt(n);
  int segment = -1;

  for(int i= 0; i<n; i++){

    if(i % sqr == 0) segment++;

    value[segment] += arr[i];
  }
}

ll query(int l, int r, int n){
  int sqr = sqrt(n);
  int sum = 0;

  while(l < r and l%sqr != 0){
    sum += arr[l];
    l++;
  }

  while(l + sqr <= r){
    sum += value[l/sqr];
    l+=sqr;
  }

  while(l<=r){
    sum += arr[l];
    l++;
  }

  return sum;
}
void anotherUpdate(int n, int i, int val){
  int sqr = sqrt(n);
  int segment = i/sqr;

  value[segment] -= arr[i];
  value[segment] += val;
  arr[i] = val;
}

ll sumOfDigits(string s){
  ll sum = 0;
  for(int i = 0; i<s.length(); i++){
    sum += (s[i]-'0');
  }
  return sum;
}

void update(int l, int r, int n){
  ll sum = query(l, r, n);
  //cout<<sum<<endl;

 for(int i = l; i<=r; i++){
  anotherUpdate(n, i, sumOfDigits(to_string(arr[i])));
 }
}


/*........................start.............................*/

void solve(){

 int t;
 cin>>t;


 while(t--){

  int n, q;
  cin>>n>>q;

  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  build(n);
  while(q--){
    int cmd;
    cin>>cmd;

    if(cmd == 1){
      int l, r;
      cin>>l>>r;
      update(l-1, r-1, n);
    }else {
      int x;
      cin>>x;
      cout<<arr[x-1]<<endl;
    }
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




