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
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int ce = 0;
    for (char c: s) {
      if (c == 'E') {
        ce ^= 1;
      }
    }
    if (ce) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int pt1{1}, pt2{2};
      for (char c: s) {
        if (c == 'O') {
          cout << pt1 << " " << pt2 << endl;
          pt1 += 2;
          pt2 += 2;
        } else {
          if (pt1 < pt2) {
            cout << pt1 << " " << pt1 + 2 << endl;
            pt1 += 4;
          } else {
            cout << pt2 << " " << pt2 + 2 << endl;
            pt2 += 4;
          }
        }
      }
    }
  }
}
