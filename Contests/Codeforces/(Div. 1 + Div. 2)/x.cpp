/*
Author: jubair7
Date: 30 Aug 2023
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> frq, frq2;
    for(int i = 0; i<s2.length(); i++)
      frq[s2[i]]++;
    for(int i = 0; i<s1.length(); i++)
      frq2[s1[i]]++;
    if(n <= k) s1 == s2 ? cout << "YES\n" : cout << "NO\n";
    else if(frq.size() == frq2.size()){
      int ok = 1;
      for(auto i : frq2){
        if(frq[i.first] != i.second){
          ok = 0;
          break;
        }
      }
      if(ok){
        int l = 0+k;
        int r = (n-1)-k;
        if(l > r){
          for(int i = r+1; i<l; i++){
            if(s1[i] != s2[i]){
              ok = 0;
              break;
            }
          }
          if(ok) cout << "YES" << '\n';
          else cout << "NO" << '\n';
        }else cout << "YES" << '\n';
      }else cout << "NO" << '\n';
    }else cout << "NO" << '\n';
  }
  return 0;
}