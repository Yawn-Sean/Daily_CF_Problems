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

  int n;
  cin >> n;
  vector<int> a(n), dp(n + 1), st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int cur{};
    while (!st.empty() && st.back() < a[i]) {
      cur = max(cur, dp[st.back()]);
      st.pop_back();
    }
    if (!st.empty()) {
      dp[a[i]] = cur + 1;
    }
    st.push_back(a[i]);
  }
  cout << ranges::max(dp) << endl;
}
