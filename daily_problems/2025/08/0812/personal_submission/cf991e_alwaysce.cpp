#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::swap;
using std::vector;
using std::string;
using i64 = int64_t;

i64 comb[20][20];
void init_comb() {
  for (int i = 0; i < 20; i++) {
    comb[i][0] = 1;
    comb[i][i] = 1;
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init_comb();
  string s;
  cin >> s;

  vector<int> cnt(10);
  for (auto& ch : s) {
    ++cnt[ch - '0'];
  }
  int n = s.size();

  i64 ans = 0;
  for (int slen = 1; slen <= n; slen++) {
    vector<i64> dp(n + 1);
    dp[0] = 1;
    for (int d = 0; d < 10; d++) {
      if (cnt[d] > 0) {
        vector<i64> ndp(n + 1);
        for (int j = slen; j > 0; j--) {
          for (int k = 1; k <= cnt[d] && k <= j; k++) {
            int tot_space = slen - (j - k);
            // 0 cannot be placed at front.
            if (d == 0) {
              tot_space--;
            }
            if (k <= tot_space) {
              ndp[j] += dp[j - k] * comb[tot_space][k];
            }
          }
        }
        swap(dp, ndp);
      }
    }
    ans += dp[slen];
  }
  cout << ans << endl;
  return 0;
}
