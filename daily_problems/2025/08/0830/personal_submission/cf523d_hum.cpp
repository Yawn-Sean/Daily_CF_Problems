#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  priority_queue<long long, vector<long long>, greater<>> pq;

  for (int i = 0; i < k; i++) {
    pq.push(0);
  }

  for (int i = 0; i < n; i++) {
    long long s, m;
    cin >> s >> m;

    long long t = pq.top();
    pq.pop();
    t = max(t, s) + m;

    cout << t << '\n';
    pq.push(t);
  }
}
