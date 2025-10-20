#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
vector<int> rk(51);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 15; i++) {
    rk[primes[i]] = i;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> cnt(51);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x]++;
    }

    auto defact = [&](int x) {
      map<int, int> mp;
      int msk = 0;
      for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
          x /= i;
          ++mp[i];
        }
      }
      if (x > 1) {
        ++mp[x];
      }
      for (auto& [k, v] : mp) {
        msk |= (1 << rk[k]);
      }
      return msk;
    };

    i64 ans = 4e18;
    vector<int> masks;
    for (int i = 2; i <= 50; ++i) {
      if (cnt[i] == 0) continue;
      masks.push_back(defact(i));
    }

    int MX = (1 << 15);
    for (int i = 0; i < MX; i++) {
      bool ok = true;
      for (auto msk : masks) {
        if ((i & msk) == 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        i64 tmp = 1;
        for (int j = 0; j < 15; j++) {
          if ((i >> j) & 1) {
            tmp = tmp * 1ll * primes[j];
          }
        }
        ans = min(ans, tmp);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
