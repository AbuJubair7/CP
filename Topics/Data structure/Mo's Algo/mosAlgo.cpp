#include<bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5 * 2 + 5;
static int segment = 555;
static int arr[mx];
static int ans[mx];
static int freq[1000001];
static int cnt = 0;

struct query{
	int l, r, ind;
};

bool cmp(query q1, query q2){

	if(q1.l/segment != q2.l/segment)
		return q1.l/segment < q2.l/segment;
	return q1.r < q2.r;
}

void add(int n){
	freq[n]++;
	if(freq[n] == 1) cnt++;
}

void remove(int n){
	freq[n]--;
	if(freq[n] == 0) cnt--;
}

void solve(){
	int n,q;
	vector<query> v;

	cin>>n;
	segment = sqrt(n);

	for(int i = 0; i<n; i++) cin>>arr[i];
	cin>>q;
	
	for(int i = 0; i<q; i++){
		int a, b;
		cin>>a>>b;
		a--; b--;
		query qu;
		qu.l = a;
		qu.r = b;
		qu.ind = i+1;
		v.pb(qu);
	}

	sort(v.begin(), v.end(), cmp);

	int lastL = v[0].l;
	int lastR = v[0].r;

	for(int i = lastL; i<=lastR; i++)
		add(arr[i]);
	
	ans[v[0].ind] = cnt;

	for(int i = 1; i<v.size(); i++){
		int l = v[i].l;
		int r = v[i].r;
		int ind = v[i].ind;

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

		ans[ind] = cnt;
	}

	// printing ans
	for(int i = 1; i<=q; i++)
		cout<<ans[i]<<endl;

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