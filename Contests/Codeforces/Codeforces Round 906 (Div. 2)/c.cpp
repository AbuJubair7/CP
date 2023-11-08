/*
Author: jubair7
Date: 28/10/23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 == 1) cout << -1 << '\n';
        else {
            int op = 0;
            int len = n-1;
            int i = 0;
            int j = len;
            vector<int> ans;
            while (i < j and op <= 300) {
                // cout << i << ' ' << j << '\n';
                if (s[i] == s[j]) {
                    if (s[i] == '1') {
                        // cout << s << '\n';
                        if (i == 0) {
                            s.insert(0, "01");
                            ans.push_back(0);
                        } else {
                            s.insert(i, "01");
                            ans.push_back(i);
                        }
                        op++;
                        i = 0;
                        j = s.length()-1;
                        continue;
                    } else {
                        // cout << s << '\n';
                        if (j == s.length()-1) {
                            ans.push_back(s.length());
                            s += "01";
                        } else {
                            s.insert(j+1, "01");
                            ans.push_back(j+1);
                        }
                        op++;
                        i = 0;
                        j = s.length()-1;
                        continue;
                    }
                }
                i++;
                j--;
            }
            int ok = 1;
            i = 0;
            j = s.length()-1;
            while ( i < j) {
                if (s[i] == s[j]) {
                    ok = 0;
                    break;
                }
                i++;
                j--;
            }
            // cout << s << '\n';
            if (ok and op <= 300) {
                cout << op << '\n';
                for (auto i : ans) cout << i << ' ';
                cout << '\n';
            } else cout << -1 << '\n';
        }
    }
    return 0;   
}