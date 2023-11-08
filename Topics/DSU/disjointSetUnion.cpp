#include<bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int sets;
int par[27];

void makeSet(int n){
	for(int i = 1; i<=n; i++){
		par[i] = i;
	}
	sets= n;
}

int find(int x){
	if(par[x] == x) return x;

	par[x] = find(par[x]);

	return par[x];
}

void UNION(int u, int v, int rank[]){

	int i = find(u);
	int j = find(v);

	if(i == j){
		return;
	}else{
		if(rank[i] > rank[j]){
			par[j] = i;

		}else if(rank[i] < rank[j]) {
			
			par[i] = j;
		}else{
			par[i] = j;
			rank[j] += 1;
		}

		sets--;
	}
}


int main(){

	// this program will find how many disjoint sub-graphs are there
	int t;
	cin>>t;
	char bigNode;
	string s;
	int putFirst = 0;

	while(t--){
		

		cin>>bigNode;

		int rank[27];
		memset(rank, 0, sizeof(rank));

		makeSet(bigNode - 'A'+1);
		

		getline(cin, s); // flush the newline out of the buffer

		while(getline(cin, s) and !s.empty()){
			UNION(s[0] -'A'+1, s[1] - 'A'+1, rank);
		}

	
		if(putFirst)
            cout<<"\n";

        putFirst = 1;
       	cout<<sets<<endl;

	}



	
	return 0;	
}