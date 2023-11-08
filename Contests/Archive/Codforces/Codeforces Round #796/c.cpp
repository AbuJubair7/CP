/*
Author: Jubair_7
Date: 3 June 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
  if(b == 0)
    return a;
  return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
  return (a*b)/gcd(a,b);
}

/*........................start.............................*/
void solve(){
  ll t;
  cin>>t;

  while(t--){
    


int n;
  cin >>n;
  n = 2*n;
  unordered_map<int ,int> m;
  string a[n];
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  string final;
  cin >> final;
  for(int i=0;i<n;i++){
    for(int j=0;j<a[i].length();j++){
      m[a[i][j]-'a']++;
    }
  }
  for(int i=0;i<final.length();i++){
    m[final[i]-'a']++;
  }
  char ans;
  for(int i=0;i<26;i++){
    if(m[i]%2!=0){
      ans = i;
      break;
    }
  }
  cout << (char)(ans+'a') << endl;
  }
}

int main(){
  BOOST;
  solve();
  return 0;
}
