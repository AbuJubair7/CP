int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
      x = 1;
      y = 0;
      return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int inverse(int a, int m) {
  int x, y;
  int g = extended_euclid(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}