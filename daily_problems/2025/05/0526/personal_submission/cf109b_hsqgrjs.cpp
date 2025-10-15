#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

std::vector<i64> t;

void solve() {
  i64 pl, pr, vl, vr, k;
  std::cin >> pl >> pr >> vl >> vr >> k;

  int t1 = std::lower_bound(t.begin(), t.end(), pl) - t.begin();
  i64 cnt = 0;
    {
        i64 pre = pl - 1;
        while (t1 + k - 1 < t.size() && t[t1] <= pr) {
          i64 L = (t[t1] - pre);
      
          i64 l1 = t[t1 + k - 1], r1 = t[t1 + k] - 1;
          if (l1 < vl)
            l1 = vl;
          if (r1 > vr)
            r1 = vr;
          if (l1 > r1) {
            pre = t[t1];
            t1++;
            continue;
          }
          i64 R = (r1 - l1 + 1);
          if (L * R > 0)
            cnt += L * R;
          pre = t[t1];
          t1++;
        }
        if (t1 > 0) {
          i64 L = pr - pre;
            i64 l1 = t[t1 + k - 1], r1 = t[t1 + k] - 1;
            if (l1 < vl)
                l1 = vl;
            if (r1 > vr)
                r1 = vr;
            if (l1 <= r1) {
            i64 R = (r1 - l1 + 1);
            if(L * R > 0)
                cnt += L * R; 
            }
        }
    }
    std::swap(pl, vl);
    std::swap(pr, vr);
    t1 = std::lower_bound(t.begin(), t.end(), pl) - t.begin();
  {
    i64 pre = pl - 1;
    while (t1 + k - 1 < t.size() && t[t1] <= pr) {
      i64 L = (t[t1] - pre);
      i64 l1 = t[t1 + k - 1], r1 = t[t1 + k] - 1;
      
      if (l1 < vl)
        l1 = vl;
      if (r1 > vr)
        r1 = vr;
      if (l1 > r1) {
        pre = t[t1];
        t1++;
        continue;
      }
      i64 R = (r1 - l1 + 1);
      if(L * R > 0) {
        cnt += L * R;
        if(t[t1] == l1) {
          cnt--;
        }
      }
      pre = t[t1];
      t1++;
    }
    if (t1 > 0) {
        i64 L = pr - pre;
            i64 l1 = t[t1 + k - 1], r1 = t[t1 + k] - 1;
            if (l1 < vl)
            l1 = vl;
          if (r1 > vr)
          r1 = vr;
            if (l1 <= r1) {
                i64 R = (r1 - l1 + 1);
                if(L * R > 0) {
                  cnt += L * R;
                  if(pr == l1) cnt--;
                }
            }
    }
  }
  std::cout << std::fixed << std::setprecision(20)
            << (long double)1.0 * cnt / (1LL * (pr - pl + 1) * (vr - vl + 1))
            << "\n";
}
void pre() {
  t.push_back(4);
  t.push_back(7);

  i64 q = 10;
  int n = 14;
  while (n--) {
    i64 s = t.size();
    for (int i = std::lower_bound(t.begin(), t.end(), q / 10) - t.begin();
         i < s; i++) {
      t.push_back(t[i] + q * 4);
      t.push_back(t[i] + q * 7);
    }
    q *= 10;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  pre();
  std::sort(t.begin(), t.end());
  solve();
  return 0;
=======
#include <array>
#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
struct ball {
    int x, c;
};
void solve() {
    int n;
    std::cin >> n;
    std::vector<ball> a(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].c;
    }
    std::sort(a.begin() + 1, a.end(), [](ball x, ball y) {
        return x.x < y.x;
    });

    const i64 inf = 1E16;
    std::array<i64, 3001> dp[2];
    for(int i = 1; i <= n; i++) {
        dp[0][i] = dp[1][i] = inf; 
    }

    dp[1][1] = a[1].c;
    for(int i = 2; i <= n; i++) {
        i64 pre = a[i].x;
        for(int j = i - 1; j > 0; j--) {
            dp[0][i] = std::min(dp[0][i], dp[1][j] + pre - 1LL * (i - j) * a[j].x);
            pre += a[j].x;
        }
        dp[1][i] = std::min(dp[0][i - 1], dp[1][i - 1]) + a[i].c;
    }

    std::cout << std::min(dp[0][n], dp[1][n]) << "\n";
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
