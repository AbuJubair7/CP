
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const int mx = 1e5+5;
static int arr[mx];
int n;
string s1, s2;

int findSub(int i, int j){

	if(j == s2.length()) return 1;

	if(i == s1.length()) return 0;

	if(s1[i] == s2[j]){
		j++;
	}
	else{
		j = 0;
	}

	return findSub(i+1, j) * 1;
}

/*........................start.............................*/
void solve(){

	cin>>n;
	cin>>s1>>s2;

	if(findSub(0, 0)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
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

