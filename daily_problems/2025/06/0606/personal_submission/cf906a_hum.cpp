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

  int msk1 = (1 << 26) - 1, msk2 = 0;
  int flg = 0, ans = 0;

  for (int i = 0; i < n - 1; i++) {
    char c;
    cin >> c;

    if (c != '.') ans += flg;

    string w;
    cin >> w;

    int cur_msk = 0;
    for (auto &ch: w)
      cur_msk |= 1 << ch - 'a';

    if (c == '!') msk1 &= cur_msk;
    else msk2 |= cur_msk;

    int val = msk1 - (msk1 & msk2);
    if ((val & -val) == val) flg = 1;
  }

  cout << ans;
}
