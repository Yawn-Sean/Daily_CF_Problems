#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    /*
    上一个状态是h=1 还是h=2

    如果当前x s[x] = 0
    两种都可以
    dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2*a + b)
    
    如果当前x s[x] = 1
    只有升上去才可以 所以 dp[x][1] = min(dp[x][0] + 2*b + a), dp[x][1] + a
    */
    i64 inf = 1e15;
    vector<array<i64, 2>> dp(n + 1, {inf, inf});
    dp[0][0] = b;
    for (int i = 0; i < n; i++) {
        for (int h = 0; h < 2; h++) {
            if (dp[i][h] >= inf) continue;
            for (int nh = 0; nh < 2; nh++) {
                if (s[i] == '1' && (h == 0 || nh == 0)) continue;
                i64 cost = a;
                if (h != nh) { cost += a; }
                cost += (nh > 0 ? 2 : 1) * b;
                dp[i + 1][nh] = min(dp[i + 1][nh], dp[i][h] + cost);
            }
        }
    }

    cout << dp[n][0] << endl;
  }
  return 0;
}
