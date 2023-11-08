/*
Algorithm name: Sliding window
For the problem of 1690D Codeforces Div-3
Example collected from (https://www.geeksforgeeks.org/window-sliding-technique/)

Abstract: Window Sliding Technique is a computational technique 
which aims to reduce the use of nested loop and replace it with a single loop, 
thereby reducing the time complexity.

The use of Sliding Window technique can be done in a very specific scenario, 
where the size of window for computation is fixed throughout the complete nested loop. 
Only then the time complexity can be reduced. 

sample question: Given an array of integers of size ‘n’, 
Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array.

*/

#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long n, k;
	cin>>n>>k;
	long long arr[n];
	long long maxSum = 0;

	for(long long i = 0; i<n; i++) cin>>arr[i];

	for(long long i = 0; i<k; i++) maxSum += arr[i];

	long long tempSum = maxSum;
	
	for(long long i = k; i<n; i++){
		tempSum += arr[i] - arr[i-k];
		maxSum = max(maxSum, tempSum);
	}

	cout<<maxSum<<endl;

}

int main(){
	long long t;
	cin>>t;

	while(t--){
		solve();
	}
	return 0;

}