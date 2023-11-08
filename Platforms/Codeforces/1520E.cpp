/*
Author: jubair7
Date: 8/11/23
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	int tCase = 0;
	while (tt-- > 0) {
		tCase++;
		int n;
		cin >> n;
		string s;
		cin >> s;
		int tot = 0;
		int l = -1;
		int r = -1;
		for (int i = 0; i<n; i++) {
			if (s[i] == '*') tot++;
			if (s[i] == '*') {
				if (l == -1) l = i;
				r = i;
			}
		}
		if (tot == 0 or tot == n or tot == 1) cout << 0 << '\n';
		else {
			vector<long long> opFront(n);
			vector<long long> opBack(n);
			long long task = 0;
			int cnt = 0;
			for (int i = 0; i<n; i++) {
				if (s[i] == '*') cnt++;
				else task += cnt;
				opFront[i] = task;
			}
			task = 0;
			cnt = 0;
			for (int i = n-1; i>=0; i--) {
				if (s[i] == '*') cnt++;
				else task += cnt;
				opBack[i] = task;
			}
			long long ans = LONG_LONG_MAX;
			int ok = 0;
			for (int i = 0; i<n-1; i++) {
				if (s[i] == '*' and s[i+1] == '.') {
					int j = i+1;
					while (j < n and s[j] != '*') j++;
					if (j < n) {
						int dis = j - i - 1;
						long long tmp = 0;
						if (dis % 2 == 1) {
							tmp = opFront[i+dis/2+1] + opBack[j-dis/2];
							tmp = min(tmp, opFront[i+dis/2] + opBack[j-dis/2-1]);
						} else {
							tmp += (opFront[i+dis/2] + opBack[j-dis/2]);	
						}
						tmp = min(tmp, min(opFront[j-1]+opBack[j], opBack[i+1]+opFront[i]));
						ok = 1;
						ans = min(tmp, ans);
					}
				}
			}
			if (ok) cout << ans << '\n';
			else cout << 0 << '\n';
		}
	}
}