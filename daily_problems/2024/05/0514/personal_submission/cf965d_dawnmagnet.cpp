#include <bits/stdc++.h>
#define REP(i, j) for (int i = 0; i < j; ++i)
using namespace std;
using ll = int64_t;
int st[100000];
int n, k;
bool check(int num) {
  st[0] = num;
  int l = 0, r = 1, rrem = st[1];
  while (l <= n) {
    int tmp = st[l];
    while (tmp) {
      if (tmp > rrem) {
        tmp -= rrem;
        rrem = 0;
        r++;
        if (r > n)
          return l + k >= n;
        if (r - l > k)
          return false;
        rrem = st[r];
      } else {
        rrem -= tmp;
        tmp = 0;
        break;
      }
    }
    l++;
  }
  return true;
}

int main() {
  cin >> n >> k;
  REP(i, n) cin >> st[i + 1];
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;

  //   REP(i, 20) { cout << i << ' ' << check(i) << '\n'; }
}