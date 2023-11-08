/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 17 Dec 2022
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

static vector<int> nodes[1000];
static int visited[1000];
static stack<int> st;

void dfs(int s){

   if(visited[s]) return;

   for(auto i : nodes[s]){
    dfs(i);
   }

   visited[s] = 1;
   st.push(s);
}

/*........................start.............................*/
void solve(){

    
    int n, m;
    cin>>n>>m;
    
    while(n != 0  || m != 0){
        
        memset(visited, 0, sizeof visited);
        for(int i = 1; i<=n; i++) nodes[i].clear();

        for(int i = 0; i<m; i++){
            int a, b;
            cin>>a>>b;
            nodes[a].pb(b);
        }

        for(int i = 1; i<=n; i++){
            dfs(i);
        }
        int p = 0;
        while(!st.empty()){

            if(p) cout<<" ";
            p = 1;
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
        cin>>n>>m;
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




