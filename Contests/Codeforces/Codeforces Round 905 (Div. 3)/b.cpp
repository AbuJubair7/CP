/*
Author: jubair7
Date: 22/10/23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while (tt--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        map<char, int> mp;
        for (auto i : s) mp[i]++;
        int remove = 0;
        int oddTaken = 0;
        int totalCharacter = 0;
        for (auto i : mp) {
            if (i.second % 2 == 1 and oddTaken) {
                i.second -= 1;
                remove++;
            } else if (i.second % 2 == 1) {
                oddTaken = 1;
            }
            totalCharacter += i.second;
        }
        k -= remove;
        if ((k < 0 or totalCharacter < k ) ) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
        }
    }
    return 0;   
}