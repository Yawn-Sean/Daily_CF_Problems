#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long t, w, b;
  cin >> t >> w >> b;
  __int128 l = (__int128) w / gcd(w, b) * b;
  long long k = t / l;
  long long res = k;
  res += k * (min(w, b) - 1);
  long long end = t - k * l;
  res += min({end, w - 1, b - 1});
  long long g = gcd(res, t);
  cout << res / g << '/' << t / g << '\n';
}
