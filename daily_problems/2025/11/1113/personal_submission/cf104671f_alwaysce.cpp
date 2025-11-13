#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
  int _and = -1;
};
Info operator+(Info a, Info b) {
  Info c;
  c._and = a._and & b._and;
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, q;
  cin >> n >> k >> q;

  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  vector<Info> init(n);
  for (int i = 0; i < n; ++i) {
    if ((nums[i] & k) == k) {
      init[i]._and = nums[i] - k;
    } else {
      init[i]._and = -1;
    }
  }

  SegmentTree<Info> seg(init);
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;

    auto res = seg.rangeQuery(l, r);
    if (res._and) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}
