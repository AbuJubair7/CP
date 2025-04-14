const int N = 1e7 + 1;
int spf[N];

void sieve(int n) {
  for(int i = 2; i < n; i++) {
    if(spf[i] > 0) continue;
    for(int j = i; j < n; j += i) {
      if(spf[j] == 0) {
          spf[j] = i;
      }
    }
  }
  spf[0] = -1;
}