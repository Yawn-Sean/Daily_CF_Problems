#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int MX = 10000;

inline int mod(int a, int m) { return (a % m + m) % m; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;
  vector<int> a(m), b(n);
  for (int i = 0; i < m; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<int> cnt(MX);

  vector<int> dA(m - 1), dB(n - 1);
  for (int i = 0; i + 1 < m; i++) {
    dA[i] = mod(a[i + 1] - a[i], MX);
  }
  for (int i = 0; i + 1 < n; i++) {
    dB[i] = mod(b[i + 1] - b[i], MX);
  }

  vector<int> lps(n - 1);
  for (int i = 1, len = 0; i < n - 1;) {
    if (dB[i] == dB[len]) {
      lps[i++] = ++len;
    } else {
      if (len) {
        len = lps[len - 1];
      } else {
        lps[i++] = 0;
      }
    }
  }

  for (int i = 0, j = 0; i < m - 1;) {
    if (dA[i] == dB[j]) {
      i++;
      j++;
      if (j == n - 1) {
        int start = i - (n - 1);
        int s = mod(b[0] - a[start], MX);
        cnt[s]++;
        j = lps[j - 1];
      }
    } else {
      if (j) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  int bestS = 0, bestC = cnt[0];
  for (int s = 1; s < MX; s++) {
    if (cnt[s] > bestC) {
      bestC = cnt[s];
      bestS = s;
    } else if (cnt[s] == bestC && s < bestS) {
      bestS = s;
    }
  }
  cout << bestS << ' ' << bestC << '\n';
  return 0;
}
