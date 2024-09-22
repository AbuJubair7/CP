/**
 *    author:  jubair7
 *    created: 22.09.2024 10:11:26
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
      vector<int> pattern;
      node () {
        end = false;
        fail = NULL;
        for (int i = 0; i < 26; i++) 
          this->adj[i] = NULL;
      }
    } * root;
    unordered_map<node*, bool> visited;
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
      curr->pattern.push_back(ind);
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
          if (!visited[curr->adj[i]]) {
            dfs(curr->adj[i]);
          }
          q.push(curr->adj[i]);
        }
      }
    }
    vector<int> dfs(node* curr) {
      vector<int> &p = curr->pattern;
      vector<int> p2;
      visited[curr] = true;
      if (curr->fail and curr != root) {
        if (visited[curr->fail]) {
          p.insert(p.end(), curr->fail->pattern.begin(), curr->fail->pattern.end());
          return p;
        }
        p2 = dfs(curr->fail);
        p.insert(p.end(), p2.begin(), p2.end());
      }
      return p;
    }
    vector<int> search (string s, int n) {
      node* curr = root;
      vector<int> ans(n);
      for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        while (curr != root and !curr->adj[id]) 
          curr = curr->fail;
        curr = (curr->adj[id] ? curr->adj[id] : root);
        for (auto p : curr->pattern) {
          ans[p]++;
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
      if (!mp[q]) {
        aho->insert(q, i);
        mp[q] = i + 1;
        queries[i] = mp[q] - 1;
      } else { 
        queries[i] = mp[q] - 1;
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