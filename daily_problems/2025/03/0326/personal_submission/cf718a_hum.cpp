#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  int p = s.find('.');
  int x = p + 1;
  while (x < n && s[x] < '5') {
    x++;
  }
  if (x == n) {
    cout << s << endl;
    return 0;
  }
  while (t--) {
    if (s[x] < '5') {
      break;
    }
    s.erase(x);
    x = s[x - 1] == '.' ? x - 2 : x - 1;
    while (~x and s[x] == '9') {
      s[x--] = '0';
    }
    if (x < 0) {
      s = '0' + s;
      x++, p++;
    }
    s[x]++;
    if (x < p) {
      break;
    }
  }
  if (s.back() == '.') {
    s.pop_back();
  }

  cout << s;
}
