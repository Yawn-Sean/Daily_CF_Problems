#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<i64> s(n), m(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> m[i];
  }

  priority_queue<pair<i64, int>> pq;
  for (int i = 0; i < k; i++) {
    pq.push(make_pair(0, i));
  }

  for (int i = 0; i < n; i++) {
    auto [time, idx] = pq.top();
    time = -time;
    pq.pop();
    i64 start_time = max(time, s[i]);
    i64 end_time = start_time + m[i];
    cout << end_time << endl;
    pq.push(make_pair(-end_time, idx));
  }
  return 0;
}
