struct node {
  node* adj[26 + 7];
  bool end;
  node () {
    end = false;
    for (int i = 0; i<=26; i++) {
      this->adj[i] = NULL;
    }
  }
} * root;

void insert (string s) {
  node* curr = root;
  for (int i = 0; i<s.length(); i++) {
    int id = s[i] - 'a';
    if (curr->adj[id] == NULL)
      curr->adj[id] = new node();
    curr = curr->adj[id];
  }
  curr->end = true;
}

bool find (string s) {
  node* curr = root;
  for (int i = 0; i<s.length(); i++) {
    int id = s[i] - 'a';
    if (curr->adj[id] == NULL)
      return false;
    curr = curr->adj[id];
  }
  return curr->end;
} 

bool findP (string s) {
  node* curr = root;
  for (int i = 0; i<s.length(); i++) {
    int id = s[i] - 'a';
    if (curr->adj[id] == NULL)
      return false;
    curr = curr->adj[id];
  }
  return true;
}

void del (node* curr) {
  for (int i = 0; i<=26; i++) {
    if (curr->adj[i])
      del(curr->adj[i]);
  }
  delete(curr);
}
