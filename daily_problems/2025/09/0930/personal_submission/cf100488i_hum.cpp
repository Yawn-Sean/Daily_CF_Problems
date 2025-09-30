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

  int n, l, r;
  cin >> n >> l >> r;

  string s;
  cin >> s;

  vector<char> stk_left(s.begin(), s.begin() + l - 1), stk_right(s.begin() + r, s.end());
  deque<char> que_mid(s.begin() + l - 1, s.begin() + r);

  reverse(stk_right.begin(), stk_right.end());

  int q;
  cin >> q;

  int flg = 1;

  while (q--) {
    char t;
    cin >> t;

    if (t == 'Q') {
      char c;
      cin >> c;
      cout << (((c == 'L') == flg) ? que_mid.front() : que_mid.back());
    } else if (t == 'R') flg ^= 1;
    else {
      char c1, c2;
      cin >> c1 >> c2;

      if (c1 == 'L') {
        if (c2 == 'L') {
          auto v = stk_left.back();
          stk_left.pop_back();
          if (flg) que_mid.emplace_front(v);
          else que_mid.emplace_back(v);
        } else {
          char v;
          if (flg) v = que_mid.front(), que_mid.pop_front();
          else v = que_mid.back(), que_mid.pop_back();
          stk_left.emplace_back(v);
        }
      } else {
        if (c2 == 'L') {
          char v;
          if (flg) v = que_mid.back(), que_mid.pop_back();
          else v = que_mid.front(), que_mid.pop_front();
          stk_right.emplace_back(v);
        } else {
          auto v = stk_right.back();
          stk_right.pop_back();
          if (flg) que_mid.emplace_back(v);
          else que_mid.emplace_front(v);
        }
      }
    }
  }
}
