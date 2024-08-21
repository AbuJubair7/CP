/*
Author: jubair7
Date: 10/6/24
*/
#include<bits/stdc++.h>
 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

map<char, int> mp;

struct node {
  node* adj[100];
  bool end;
  int visited;
  node () {
    end = false;
    visited = 0;
    for (int i = 0; i<=90; i++) {
      this->adj[i] = NULL;
    }
  }
} * root;

void insert (string s) {
  node* curr = root;
  for (int i = 0; i<s.size(); i++) {
    int id = mp[s[i]];
    if (curr->adj[id] == NULL)
      curr->adj[id] = new node();
    curr = curr->adj[id];
  }
  curr->visited++;
  curr->end = true;
}

int find (string s) {
  node* curr = root;
  for (int i = 0; i<s.size(); i++) {
    int id = mp[s[i]];
    if (curr->adj[id] == NULL)
      return 0;
    curr = curr->adj[id];
  }
  return (curr->end == true ? curr->visited : 0);
} 

void del (node* curr) {
  for (int i = 0; i<=90; i++) {
    if (curr->adj[i])
      del(curr->adj[i]);
  }
  delete(curr);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int tt;
  cin >> tt;
  int tCase = 1;
  int ind = 1;
  for (char i = 'a'; i <= 'z'; i++) mp[i] = ind++;
  for (char i = 'A'; i <= 'Z'; i++) mp[i] = ind++;
  while (tt--) {
    root = new node();
    int n, q;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (s.length() >= 2)
        sort(s.begin() + 1, s.end() - 1);
      insert(s);
    }
    cin >> q;
    cin.ignore();
    cout << "Case " << tCase++ << ":" << '\n';
    while (q--) {
      long long ans = 1, cnt = 0;
      string s;
      getline(cin, s);
      istringstream ss(s);
      string word;
      while (ss >> word) {
        cnt++;
        if (word.length() >= 2)
          sort(word.begin() + 1, word.end() - 1);
        ans *= find(word); 
      }
      if (!cnt) ans = 0;
      cout << ans << '\n';
    }
    del(root);
  }
  return 0;
}
