/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 10 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5*2 + 5;


void solve(){

	int t;
	int tCase = 1;

	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;

		int a = 0;
		int b = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i] == 'b') b = 1;
			else a = 1;
			if(a and b) break;

		}

		if(a and b){
			if(s[0] == 'b'){
				if(s[0] == s[1]){
					cout<<s[0]<<" ";
					for(int i = 1; i<s.length()-1; i++)cout<<s[i];
					cout<<" "<<s[s.length()-1]<<endl;
				}else{
					cout<<s[0]<<" "<<s[1]<<" ";
					for(int i = 2; i<s.length(); i++) cout<<s[i];
					cout<<endl;
				}
				
			}else{
				if(s[0] == s[1]){
					cout<<s[0]<<" "<<s[1]<<" ";
					for(int i = 2; i<s.length(); i++) cout<<s[i];
					cout<<endl;
				}else{
					cout<<s[0]<<" ";
					for(int i = 1; i<s.length()-1; i++)cout<<s[i];
					cout<<" "<<s[s.length()-1]<<endl;
				}
				
			}
			

		}else{

			cout<<s[0]<<" ";
			for(int i = 1; i<s.length()-1; i++) cout<<s[i];
			cout<<" "<<s[s.length()-1]<<endl;


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