/*
Author: jubair7
Date: 20/3/24
*/
#include<bits/stdc++.h>
 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

struct node {
  node* adj[26 + 7];
  bool end;
  node () {
    end = false;
    for (int i = 1; i<=26; i++) {
      this->adj[i] = NULL;
    }
  }
} * root;

void insert (string s) {
  int len = s.length();
  node* curr = root;
  for (int i = 0; i<len; i++) {
    int id = s[i] - 'a';
    if (curr->adj[id] == NULL) {
      curr->adj[id] = new node();
    }
    debug(i);
    curr = curr->adj[id];
  }
  curr->end = true;
}

bool find (string s) {
  int len = s.length();
  node* curr = root;
  for (int i = 0; i<len; i++) {
    int id = s[i] - 'a';
    if (curr->adj[id] == NULL)
      return false;
    curr = curr->adj[id];
  }
  return curr->end;
} 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    insert(s);
    
  }
}