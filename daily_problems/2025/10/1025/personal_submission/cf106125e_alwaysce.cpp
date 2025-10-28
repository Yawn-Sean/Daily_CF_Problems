#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int p = 0;
  vector<int> bits(n + 1);
  auto ask = [&](int l, int r) {
    cout << l << ' ' << r << endl;
    for (int i = 1; i <= n; i++) {
      cin >> bits[i];
    }
    cin >> p;
  };

  int MX = 125;

  vector<int> cnt(n + 1);
  int mx_l = 1, mx_r = n;
  for (int i = 1; i <= MX; i++) {
    if (p >= 70) {
      break;
    }

    ask(mx_l, mx_r);
    cnt[0] = 0;
    for (int i = 1; i <= n; i++) {
      cnt[i] = cnt[i - 1] + bits[i];
    }

    // 50%概率变成0/1
    // cnt0-> cnt0/2(-') + cnt1/2(1')
    // cnt1-> cnt1/2(0') + cnt0/2(1')
    int max_gain = 0;
    for (int i = 1; i <= n; i++) {
      // [i, j]
      for (int j = i; j <= n; j++) {
        int cnt1 = cnt[j] - cnt[i - 1];
        int cnt0 = (j - i + 1) - cnt1;
        int gain = cnt0 - cnt1;
        if (gain > max_gain) {
          max_gain = gain;
          mx_l = i;
          mx_r = j;
        }
      }
    }
  }

  return 0;
}
