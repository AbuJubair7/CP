/*
Author: jubair7
Date: 18 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int t;
	cin>>t;
	while(t--){
		int n;
		double b, h;
		cin >> n >> b >> h;
		vector<double> arr(n);
		double tringle = ((b*h)/2.0);
		double dec = b/h;
		double ans = tringle;
		for(int i = 0; i<n; i++) cin >> arr[i];
		for(int i = 1; i<n; i++){
			if(arr[i]-arr[i-1] >= h)
				ans += tringle;
			else{
				double height = arr[i]-arr[i-1];
				double a = (dec * (h-height));
				double trapezium = ((height * (a+b)) / 2.0);
				ans += trapezium;
			}
		}
		cout << fixed << setprecision(6) << ans << '\n';
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}