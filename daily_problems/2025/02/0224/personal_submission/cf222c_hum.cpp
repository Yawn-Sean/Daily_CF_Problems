#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
  vector<int> minp, primes;
  minp.assign(n + 1, 0);
  primes.clear();

  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }

    for (auto p: primes) {
      if (i * p > n) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        break;
      }
    }
  }
  return minp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int M = max(ranges::max(a), ranges::max(b));
  vector<int> minp = sieve(M);
  vector<int> cnt1(M + 1), cnt2(M + 1), del1(M + 1), del2(M + 1);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x > 1) {
      int p = minp[x];
      cnt1[p]++;
      x /= p;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x = b[i];
    while (x > 1) {
      int p = minp[x];
      cnt2[p]++;
      x /= p;
    }
  }
  for (int i = 1; i <= M; ++i) {
    del1[i] = min(cnt1[i], cnt2[i]);
    del2[i] = del1[i];
  }

  vector<int> res1(n), res2(m);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int t = 1;
    while (x > 1) {
      int p = minp[x];
      if (del1[p] > 0) {
        t *= p;
        del1[p]--;
      }
      x /= p;
    }
    res1[i] = a[i] / t;
  }
  for (int i = 0; i < m; i++) {
    int x = b[i];
    int t = 1;
    while (x > 1) {
      int p = minp[x];
      if (del2[p] > 0) {
        t *= p;
        del2[p]--;
      }
      x /= p;
    }
    res2[i] = b[i] / t;
  }
  cout << n << " " << m << "\n";
  for (int i = 0; i < n; i++) {
    cout << res1[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < m; i++) {
    cout << res2[i] << " \n"[i == m - 1];
  }
}
