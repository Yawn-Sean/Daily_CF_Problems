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

  string s1, s2;
  cin >> s1 >> s2;
  int n1 = s1.size(), n2 = s2.size();
  vector<int> l(n1), pos(26, -1);
  int k = 0;
  for (int i = 0; i < n1; i++) {
    if (k < n2 && s1[i] == s2[k]) {
      l[i] = k;
      pos[s1[i] - 'a'] = k++;
    } else {
      l[i] = pos[s1[i] - 'a'];
    }
  }
  vector<int> r(n1);
  pos.assign(26, n2);
  k = n2 - 1;
  for (int i = n1 - 1; i >= 0; i--) {
    if (k >= 0 && s1[i] == s2[k]) {
      r[i] = k, pos[s1[i] - 'a'] = k--;
    } else {
      r[i] = pos[s1[i] - 'a'];
    }
  }

  for (int i = 0; i < n1; i++) {
    if (l[i] < r[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
