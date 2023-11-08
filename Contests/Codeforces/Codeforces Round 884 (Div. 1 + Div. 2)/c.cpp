/*
Author: jubair7
Date: 12 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin >> n >> s;
		vector<int> arr(n);
		int sum = 0;
		for(auto &i : arr){
			 cin >> i;
			 sum += i;
		}
		if(sum < s) cout << -1 << '\n';
		else if(sum == s) cout << 0 << '\n';
		else{
			queue<int> q;
			int tmp = 0;
			int i = 0;
			while(i < n ){
				tmp += arr[i];
				if(tmp > s){
					break;
				}else q.push(arr[i]);
				i++;
			}
			int size = q.size();
			// cout << i << '\n';
			if(tmp > s) tmp--;
			else i++;
			int ind = 0;
			while(i<n){
				while(i < n){
					if(arr[i] != 1){
						q.push(arr[i]);
					}else{
						q.push(arr[i]);
						i++;
						while(i < n and arr[i] != 1){
							q.push(arr[i]);
							i++;
						}
						while(ind < n){
							if(arr[ind] == 1){
								q.pop();
								ind++;
								break;
							}
							q.pop();
							ind++;
						}
						break;
					}
					i++;
				}
				size = max((int)q.size(), size);
			}
			cout << n-size << '\n';
		}
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}/*
Author: jubair7
Date: 12 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin >> n >> s;
		vector<int> arr(n);
		int sum = 0;
		for(auto &i : arr){
			 cin >> i;
			 sum += i;
		}
		if(sum < s) cout << -1 << '\n';
		else if(sum == s) cout << 0 << '\n';
		else{
			queue<int> q;
			int tmp = 0;
			int i = 0;
			while(i < n ){
				tmp += arr[i];
				if(tmp > s){
					break;
				}else q.push(arr[i]);
				i++;
			}
			int size = q.size();
			// cout << i << '\n';
			if(tmp > s) tmp--;
			else i++;
			int ind = 0;
			while(i<n){
				while(i < n){
					if(arr[i] != 1){
						q.push(arr[i]);
					}else{
						q.push(arr[i]);
						i++;
						while(i < n and arr[i] != 1){
							q.push(arr[i]);
							i++;
						}
						while(ind < n){
							if(arr[ind] == 1){
								q.pop();
								ind++;
								break;
							}
							q.pop();
							ind++;
						}
						break;
					}
					i++;
				}
				size = max((int)q.size(), size);
			}
			cout << n-size << '\n';
		}
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}