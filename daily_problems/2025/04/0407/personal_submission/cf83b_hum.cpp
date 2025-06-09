#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  long long sum{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < k) {
    cout << "-1\n";
    return 0;
  }

  long long l{}, r{k - 1};
  while (l < r) {
    long long mid = (r + l + 1) / 2;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += min(a[i], mid);
    }
    if (sum > k) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  for (int i = 0; i < n; i++) {
    k -= min(a[i], l);
  }
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (a[i] > l) {
      b.push_back(i);
    }
  }
  for (int i = k; i < b.size(); i++) {
    cout << b[i] + 1 << ' ';
  }
  for (int i = 0; i < k; i++) {
    if (a[b[i]] - l - 1 > 0) cout << b[i] + 1 << ' ';
  }
  cout << endl;
  return 0;
}
