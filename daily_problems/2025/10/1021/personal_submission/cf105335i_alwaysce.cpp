#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
n<=100
注意到 xx ab | xx ba
diff = 9(a-b)
10a+b - 10b-a = 9(a-b)
所以它们的gcd 一定是 18 27 36 45 54 63 72 81或者它们的约数
并且一定是两位数

所以还有 12 15  21 24 的可能
问题是怎么构造出这样的数
*/

i64 baoli(int d1, int d2, int target) {
  queue<i64> q;
  q.push(d1);
  q.push(d2);
  while (!q.empty()) {
    if (q.front() >= 1e18) {
      return -1;
    }

    i64 nxt1 = q.front() * 10 + d1;
    i64 nxt2 = q.front() * 10 + d2;
    q.pop();
    if (nxt1 != 0 && nxt1 % target == 0) {
      return nxt1;
    }
    if (nxt2 != 0 && nxt2 % target == 0) {
      return nxt2;
    }

    if (nxt1 != 0) {
      q.push(nxt1);
    }
    if (nxt2 != 0) {
      q.push(nxt2);
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> need = {12, 15, 18, 21, 24, 27, 36, 45, 54, 63, 72, 81};
  map<int, i64> mp;
  mp[12] = 48;
  mp[15] = 5055;  // 只有(5, 0)
  mp[18] = 288;
  mp[21] = 7077;
  mp[24] = 8088;
  mp[27] = 3699;
  mp[36] = 48888;

  // 因为需要5 和 9*5
  mp[45] = 5055555555;
  // mp[54] = ?; // (0,6),(1,7),(2,8),(3,9)
  // mp[63] = ?// (0,7),(1,8),(2,9)
  mp[72] = 8088888888;
  mp[81] = 9099999999;

  {
    vector<i64> v1 = {baoli(0, 6, 54), baoli(1, 7, 54), baoli(2, 8, 54),
                      baoli(3, 9, 54)};
    i64 best = -1;
    for (auto x : v1) {
      if (x == -1) continue;
      if (best == -1 || x < best) {
        best = x;
      }
    }
    if (best != -1) {
      mp[54] = best;
    }
  }
  {
    vector<i64> v2 = {baoli(0, 7, 63), baoli(1, 8, 63), baoli(2, 9, 63)};
    i64 best = -1;
    for (auto x : v2) {
      if (x == -1) continue;
      if (best == -1 || x < best) {
        best = x;
      }
    }
    if (best != -1) {
      mp[63] = best;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    i64 n;
    cin >> n;
    // 9(a-b),
    // 18 27 36 45 54 63 72 81
    if (mp.count(n)) {
      cout << mp[n] << endl;
    } else {
      set<int> digits;
      i64 ans = n;
      while (n > 0) {
        digits.insert(n % 10);
        n /= 10;
      }
      if (digits.size() > 1) {
        cout << -1 << endl;
      } else {
        cout << ans << endl;
      }
    }
  }
  return 0;
}
