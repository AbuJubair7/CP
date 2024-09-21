/**
 *    author:  jubair7
 *    created: 21.09.2024 11:05:51
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class AhoCorasick {
  private:
    struct node {
      node* adj[26];
      node* fail;
      bool end;
      int ind;
      node () {
        end = false;
        fail = NULL;
        for (int i = 0; i < 26; i++) 
          this->adj[i] = NULL;
      }
    } * root;
  public:
    AhoCorasick () {
      root = new node();
    }
    ~AhoCorasick () {
      del(root);
    }
    void insert (string s, int ind) {
      node* curr = root;
      for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if (curr->adj[id] == NULL)
          curr->adj[id] = new node();
        curr = curr->adj[id];
      }
      curr->ind = ind;
      curr->end = true;
    }
    void build_links () {
      queue<node*> q;
      for (int i = 0; i < 26; i++) {
        if (root->adj[i]) {
          root->adj[i]->fail = root;
          q.push(root->adj[i]);
        }
      }
      while (!q.empty()) {
        node* curr = q.front();
        q.pop(); 
        for (int i = 0; i < 26; i++) {
          if (!curr->adj[i]) continue;
          node* fail = curr->fail;
          while (fail != root and !fail->adj[i])
            fail = fail->fail;
          curr->adj[i]->fail = (fail->adj[i] ? fail->adj[i] : root);
          q.push(curr->adj[i]);
        }
      }
    }
    vector<int> search (string s, int n) {
      node* curr = root;
      vector<int> ans(n);
      for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        while (curr != root and !curr->adj[id]) 
          curr = curr->fail;
        curr = (curr->adj[id] ? curr->adj[id] : root);
        node *tmp = curr;
        while (tmp != root) {
          if (tmp->end) {
            ans[tmp->ind]++;
          }
          tmp = tmp->fail;
        }
      }
      return ans;
    } 
  private:
    void del (node* curr) {
      for (int i = 0; i < 26; i++) {
        if (curr->adj[i])
          del(curr->adj[i]);
      }
      delete(curr);
    }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    string s;
    int n;
    cin >> n >> s;
    AhoCorasick *aho =  new AhoCorasick();
    vector<int> queries(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      string q;
      cin >> q;
      if (mp.find(q) == mp.end()) {
        aho->insert(q, i);
        mp[q] = i;
        queries[i] = mp[q];
      } else { 
        queries[i] = mp[q];
      }
    }
    aho->build_links();
    vector<int> ans = aho->search(s, n);
    cout << "Case " << ++tCase << ":" << '\n';
    for (int i = 0; i < n; i++) {
      cout << ans[queries[i]] << '\n';
    }
    delete aho;
  }
  return 0;
}
