#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n;
  cin >> n;
  vector<int> cnt1(n);
  vector<int> cnt2(n);
  int m{};
  for (int i = 0; i < n; ++i) {
    int a, f;
    cin >> a >> f;
    a--;
    cnt1[a]++;
    cnt2[a] += f;
  }

  m = ranges::max(cnt1);
  vector<int> idx(n);
  ranges::iota(idx, 0);
  ranges::sort(idx, [&](int i, int j) { return cnt1[i] > cnt1[j]; });

  priority_queue<int> pq;
  int j{};
  int res1{}, res2{};
  for (int i = m; i >= 1; --i) {
    while (j < n && cnt1[idx[j]] == i) {
      pq.push(cnt2[idx[j]]);
      j++;
    }

    if (!pq.empty()) {
      res1 += i;
      res2 += min(pq.top(), i);
      pq.pop();
    }
  }
  cout << res1 << " " << res2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
