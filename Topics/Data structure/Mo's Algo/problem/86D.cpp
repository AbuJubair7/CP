/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 29 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e6 + 5;
static int arr[mx];
static int segment = 555;
static ll sum = 0;
static ll frq[mx];
static ll ans[mx];


struct query{
	int l, r, ind;
};

bool cmp(query q1, query q2){

	if(q1.l/segment != q2.l/segment)
		return q1.l/segment < q2.l/segment;
	return q1.r < q2.r;
}

void add(int n){
	frq[n]++;

	if(frq[n] == 1){
		sum = sum + (n);

	}else{
		sum = sum - (n * ((frq[n]-1) * (frq[n]-1)));
		sum = sum + (n * (frq[n] * frq[n]));
	}
}

void remove(int n){
	frq[n]--;

	if(frq[n] == 0){
		sum = sum - (n);
	}else{
		sum = sum - (n * ((frq[n]+1) * (frq[n]+1)));
		sum = sum + (n * (frq[n] * frq[n]));
	}
}


void solve(){
	int n, q;
	vector<query> qu;
	cin>>n>>q;

	for(int i = 0; i<n; i++){
		 cin>>arr[i];
		
	}

	for(int i = 0; i<q; i++){
		int a, b;
		cin>>a>>b;
		query q;
		q.l = a-1;
		q.r = b-1;
		q.ind = i+1;
		qu.pb(q);
	}
	segment = sqrt(n);
	sort(qu.begin(), qu.end(), cmp);

	for(int i = qu[0].l; i<=qu[0].r; i++){
		add(arr[i]);
	}
	int lastL = qu[0].l;
	int lastR = qu[0].r;
	ans[qu[0].ind] = sum;


	for(int i = 1; i<q; i++){
		int l = qu[i].l;
		int r = qu[i].r;
		int ind = qu[i].ind;

		while(l < lastL){
			lastL--;
			add(arr[lastL]);
		}

		while(l > lastL){
			remove(arr[lastL]);
			lastL++;
		}

		while(r > lastR){
			lastR++;
			add(arr[lastR]);
		}

		while(r < lastR){
			remove(arr[lastR]);
			lastR--;
		}

		ans[ind] = sum;
	}

	for(int i = 1; i<=q; i++){
		cout<<ans[i]<<endl;
	}

}

int main(){
	BOOST;

	solve();


	return 0;
}
