#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  int l{-1}, r{-1}, x{-1};
  for (int i = 0; i < n; ++i) {
    if (s[i] != '0' && s[i] != '.') {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] != '0' && s[i] != '.') {
      r = i;
      break;
    }
  }
  x = s.find('.');
  if (x == -1) x = n;
  if (l == -1) cout << "0";
  else {
    cout << s[l];
    if (l != r) {
      cout << ".";
      for (int i = l + 1; i <= r; ++i)
        if (s[i] != '.')
          cout << s[i];
    }
    if (l + 1 != x)
      cout << "E" << x - l - (l < x);
  }
}
