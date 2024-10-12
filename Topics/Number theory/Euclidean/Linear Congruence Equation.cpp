long long extended_euclid(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long inverse(long long a, long long m) {
  long long x, y;
  long long g = extended_euclid(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
// ax = b (mod m)
vector<long long> congruence_equation(long long a, long long b, long long m) {
  vector<long long> ret;
  long long g = gcd(a, m), x;
  if (b % g != 0) return ret;
  a /= g, b /= g;
  x = inverse(a, m / g) * b;
  for (int k = 0; k < g; ++k) { // exactly g solutions
    ret.push_back((x + m / g * k) % m);
  }
  // minimum solution = (m / g - (m - x) % (m / g)) % (m / g)
  return ret;
}