/**
 *    author:  jubair7
 *    created: 09.09.2024 14:35:39
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int x[4] = {1, -1, 0, 0};
const int y[4] = {0, 0, 1, -1};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    pair<int, int> start;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == '@') {
          start = make_pair(i, j);
        }
      }
    }
    auto Dfs = [&] (auto&& self, pair<int, int> u) -> int {
      int cnt = 0;
      visited[u.first][u.second] = true;
      for (int i = 0; i < 4; i++) {
        int row = u.first + x[i];
        int col = u.second + y[i];
        if (row >= 1 and row <= n and col >= 1 and col <= m and grid[row][col] == '.' and !visited[row][col]) {
          cnt += self(self, make_pair(row, col));
        }
      }
      return cnt + 1;
    };
    cout << "Case " << ++tCase << ": " << Dfs(Dfs, start) << '\n';
  }
  return 0;
}
