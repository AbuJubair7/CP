/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 27 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 5;
const int maxLog = log2(mx) + 5;
static map<int, vector<int>> adj;
static int n, level[mx], dp [mx][maxLog], root;


void dfs(int s, int p){
    dp[s][0] = p;
    if(p == -1) level[s] = 0;
    else level[s] = level[p]+1;

    for(auto i : adj[s]){   
        if(i != p){
            dfs(i, s);
        }
    }

}

void build(){
    memset(dp, -1, sizeof dp);
    /* 
        setting level and setting [i][0] value of
        sparse table
    */
    dfs(root, -1);

    //taking max logN from N
    int lg = log2(n) + 1;

    // setting the sparse table
    for(int j = 1; j<=lg; j++){

        for(int i = 1; i<=n; i++){
            
            if(dp[i][j-1] != -1){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int a, int b){
    if(level[a] < level[b]) swap(a, b);
    int d = level[a] - level[b];

    while(d > 0){
        int lg = log2(d);
        a = dp[a][lg];
        d -= (1<<lg);
    }

    if(a == b) return a;

    for(int i = log2(n) + 1; i>=0; i--){

        if(dp[a][i] != -1 and (dp[a][i] != dp[b][i])){
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    return dp[a][0];
}

int distance(int a, int b){
    return level[a]+level[b] - (2*level[LCA(a, b)]);
}

/*........................start.............................*/
void solve(){
    int t;
    cin>>t;
    int tCase = 1;
    while(t--){
        int m, q, child, a, b;
        root = 1;
        cin>>n;
        adj.clear();

        for(int i = 1; i<=n; i++){
            cin>>m;
            while(m--){
                cin>>child;
                adj[i].pb(child);
            }
        }
        
        build();
        cin>>q;
        cout<<"Case "<<tCase++<<":\n";

        // for(int i = 1; i<=n; i++){
        //     for(int j = 0; j<=log2(n); j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        while(q--){
            cin>>a>>b;
            cout<<LCA(a, b)<<endl;
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




