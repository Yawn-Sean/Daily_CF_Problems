#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
  int g = 0;
};

Info operator+(Info a, Info b) {
  Info c;
  c.g = gcd(a.g, b.g);
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int MX = 2e5;
  vector<int> f(MX + 1);
  for (int i = 1; i <= MX; i++) {
    for (int j = i; j <= MX; j += i) {
      f[j]++;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    f[0] = n;

    vector<int> nums(n);
    for (auto& ni : nums) {
      cin >> ni;
    }

    vector<Info> init(n);
    for (int i = 1; i < n; i++) {
      if (nums[i] < nums[i - 1]) {
        init[i] = Info{i};
      }
    }

    SegmentTree<Info> seg(init);

    auto answer = [&]() {
      int g = seg.rangeQuery(1, n).g;
      cout << f[g] << '\n';
      return;
    };

    answer();
    for (int i = 0; i < q; i++) {
      int p, x;
      cin >> p >> x;
      --p;
      nums[p] = x;
      if (p > 0) {
        bool bad = (nums[p] < nums[p - 1]);
        seg.modify(p, Info{bad ? p : 0});
      }
      if (p + 1 < n) {
        bool bad = (nums[p + 1] < nums[p]);
        seg.modify(p + 1, Info{bad ? p + 1 : 0});
      }
      answer();
    }
  }
  return 0;
}
