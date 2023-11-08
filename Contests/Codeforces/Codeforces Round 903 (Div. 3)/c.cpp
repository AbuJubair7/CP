/*
Author: jubair7
Date: 12 Oct 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int calculate(vector<string> edge) {
    int op = 0; 
    for (int i = 0; i<edge[0].length()-1; i++) {
        int mx = max(max(edge[0][i], edge[1][i]), max(edge[2][i], edge[3][i]));
        op += (mx - edge[0][i]);
        op += (mx - edge[1][i]);
        op += (mx - edge[2][i]);
        op += (mx - edge[3][i]);
    }
    return op;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while(tt--){
        int n;
        cin >> n;
        char ch[n+1][n+1];
        long long ans = 0;
        for (int i = 1; i<=n; i++)
            for (int j = 1; j<=n; j++)
                cin >> ch[i][j];
        vector<string> edge;
        for (int i = 1; i<=n/2; i++) {
            string s = "";
            int k = i;
            while (k <= n-i+1) {
                s += ch[i][k];
                k++;
            }
            edge.push_back(s);
            s = "";
            k = i;
            while (k <= n-i+1) {
                s += ch[k][n-i+1];
                k++;
            }
            edge.push_back(s);
            s = "";
            k = n-i+1;
            while (k >= i) {
                s += ch[n-i+1][k];
                k--;
            }
            edge.push_back(s);
            s = "";
            k = n-i+1;
            while (k >= i) {
                s += ch[k][i];
                k--;
            }
            edge.push_back(s);
            ans += calculate(edge);
            edge.clear();
        }
        cout << ans << '\n';
    }
  return 0;
}