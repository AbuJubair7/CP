int dp[1000];

int calculate(int n) {
	if (n <= 2) return n;
	if (dp[n] != -1) return dp[n];
	return dp[n] = calculate(n-1) + calculate(n-2);
}