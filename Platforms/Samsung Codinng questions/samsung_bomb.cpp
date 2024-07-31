/*
Author: jubair7
Date: 21/12/23
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MIN = -1000;
const int HEIGHT = 14, WIDTH = 8;
int arr[HEIGHT][WIDTH];
int n;

int findPath(int level, int col, int coin, int pow) {
  if (col < 1 or col > 5) return -100;
  if (level == 1) {
    if (pow > 0 and pow <= 5) {
      if (arr[level][col] == 2) return 0;
      return arr[level][col];
    } else {
      if (arr[level][col] == 2) return -1;
      return arr[level][col];
    }
  }
  int res = coin;
  if (level <= n) {
    if (pow > 0 and pow <= 5) {
      if (arr[level][col] == 2) res += 0;
      else res += arr[level][col];
    } else {
      if (arr[level][col] == 2) res -= 1;
      else res += arr[level][col];
    }
  }
  if (res < 0) return -1000;
  int val = MIN;
  int val2 = MIN;
  if (pow == -1) {
    val = max(max(findPath(level-1, col-1, res, -1),findPath(level-1, col, res, -1 )), findPath(level-1, col+1, res, -1));
    val2 = max(max(findPath(level-1, col-1, res, 1),findPath(level-1, col, res, 1 )), findPath(level-1, col+1, res, 1));
  } else {
    val2 = max(max(findPath(level-1, col-1, res, pow+1),findPath(level-1, col, res, pow+1 )), findPath(level-1, col+1, res, pow+1));
  }
  res = max(val, val2);
  if (level <= n) {
    if (pow > 0 and pow <= 5) {
      if (arr[level][col] == 2) res += 0;
      else res += arr[level][col];
    } else {
      if (arr[level][col] == 2) res -= 1;
      else res += arr[level][col];
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    tCase++;
    cin >> n;
    int dp[n+1][6][n+1];
    for (int i = 1; i<=n; i++) {
      for (int j = 1; j<=5; j++) {
        cin >> arr[i][j];
      }
    }
    // int ans = findPath(n+1, 3, 0, -1);
    // cout << "#" << tCase++ << ' ' << max(-1, ans) << '\n';
    dp[n][1][1] = -100;
    dp[n][1][0] = -100;
    dp[n][5][1] = -100;
    dp[n][5][0] = -100;
    dp[n][2][0] = (arr[n][2] == 2 ? -100 : arr[n][2]);
    dp[n][2][1] = (arr[n][2] == 2 ? 0 : arr[n][2]);
    dp[n][3][0] = (arr[n][3] == 2 ? -100 : arr[n][3]);
    dp[n][3][1] = (arr[n][3] == 2 ? 0 : arr[n][3]);
    dp[n][4][0] = (arr[n][4] == 2 ? -100 : arr[n][4]);
    dp[n][4][1] = (arr[n][4] == 2 ? 0 : arr[n][4]);
    for (int i = n-1; i>=1; i--) {
      int val = 0;
      for (int j = 1; j<=5; j++) {
        for (int k = 0; k<=(n-i)+1; k++) {
          dp[i][j][k] = -100;
          if (j == 1) {
            if (k == 0) {
              val = max(dp[i+1][j][k], dp[i+1][j+1][k]);
            } else {
              val = max(dp[i+1][j][k-1], dp[i+1][j+1][k-1]);
            }
          } else if (j == 5) {
            if (k == 0) {
              val = max(dp[i+1][j][k], dp[i+1][j-1][k]);
            } else {
              val = max(dp[i+1][j][k-1], dp[i+1][j-1][k-1]);
            }
          } else {
            if (k == 0) {
              val = max(max(dp[i+1][j-1][k], dp[i+1][j][k]), dp[i+1][j+1][k]);
            } else {
              val = max(max(dp[i+1][j-1][k-1], dp[i+1][j][k-1]), dp[i+1][j+1][k-1]);
            }
          }
          int curr = (arr[i][j] == 2 ? -1 : arr[i][j]);
          if (k > 0 and k <= 5 and curr < 0) curr++;
          dp[i][j][k] = (val >= 0 ? val : -1000);
          if (dp[i][j][k] >= 0) dp[i][j][k] += curr;
          dp[i][j][k] = (dp[i][j][k] >= 0 ? dp[i][j][k] : -1000);
        }
      }
    }
    int ans = -1;
    for (int i = 1; i<=5; i++) {
      for (int j = 0; j<=n; j++) {
        ans = max(ans, dp[1][i][j]);
      }
    }
    cout << "#" << tCase++ << ' ' << ans << '\n';
  }
}