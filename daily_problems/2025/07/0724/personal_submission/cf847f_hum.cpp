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

    int n, k, m, a;
    cin >> n >> k >> m >> a;
    vector<int> g(a);
    for (int i = 0; i < a; i++) {
      cin >> g[i], g[i]--;
    }

    function<bool(int)> check1 = [&](int i) -> bool {
      vector<int> votes(n);
      vector<int> last(n);
      for (int j = 0; j < a; j++) {
        votes[g[j]] += 1;
        last[g[j]] = j;
      }
      for (int j = a; j < m; j++) {
        int best = -1;
        for (int k = 0; k < n; k++) {
          if (votes[k] < votes[i] || (votes[k] == votes[i] && last[k] > last[i])) {
            if (best == -1 || votes[k] >= votes[best]) {
              best = k;
            }
          }
        }
        if (best == -1 && n == 1) best = 0;
        if (best != -1) {
          votes[best] += 1;
          last[best] = j;
        }
      }
      int pos = 1;
      for (int k = 0; k < n; k++) {
        if (votes[k] > votes[i] || (votes[k] == votes[i] && last[k] < last[i])) {
          pos += 1;
        }
      }
      return pos <= k && votes[i] > 0;
    };

    function<bool(int)> check2 = [&](int i) -> bool {
      vector<int> votes(n);
      vector<int> last(n);
      for (int j = 0; j < a; j++) {
        votes[g[j]] += 1;
        last[g[j]] = j;
      }
      for (int j = a; j < m; j++) {
        votes[i] += 1;
        last[i] = j;
      }
      int pos = 1;
      for (int k = 0; k < n; k++) {
        if (votes[k] > votes[i] || (votes[k] == votes[i] && last[k] < last[i])) {
          pos += 1;
        }
      }
      return pos > k || (votes[i] == 0);
    };

    for (int i = 0; i < n; i++) {
      bool win = check1(i);
      bool lose = check2(i);
      cout << (lose ? "3" : win ? "1" : "2") << " \n"[i == n - 1];
    }
  }
