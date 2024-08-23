// nCr in efficient way
long long nCr (int n, int k) {
    k = min(k, n - k); // Choose the smaller k
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}