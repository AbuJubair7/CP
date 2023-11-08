/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 30 Jan 2022
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



 while(t--){
  int n;
  cin>>n;
  vector<int> p1;
  vector<int> p2;
  ll sum1= 0;
  ll sum2 = 0;
  int lasPoint = 0;

  for(int i = 0; i<n; i++){
  	int point;
  	cin>>point;
  	if(point < 0){
  		p2.pb(abs(point));
  		sum2 += abs(point);
  	}else {
  		p1.pb(point);
  		sum1 += point;
  	}
  	lasPoint = point;
  }

  if(sum1 > sum2) cout<<"first"<<endl;
  else if(sum2 > sum1) cout<<"second"<<endl;
  else{

  	int win = 0;
  	for(int i = 0; i<min(p1.size(), p2.size()); i++){
		if(p2[i] < p1[i]){
			win = 1;
			break;
		}else if(p1[i] < p2[i]){
			win = 2;
			break;
		}
	}
	if(!win){
		if(p1.size() > p2.size()) win = 1;
		else if(p2.size() > p1.size()) win =2;
		else{
			if(lasPoint < 0) win = 2;
			else win = 1;
		}
	}
	if(win == 1) cout<<"first"<<endl;
	else cout<<"second"<<endl;

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




