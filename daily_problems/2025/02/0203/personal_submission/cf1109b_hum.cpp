#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.length();
  bool flg{};
  for (int i = 0; i < n / 2 - 1; i++) {
    if (s[i] != s[i + 1]) {
      flg = true;
      break;
    }
  }
  if (!flg) {
    cout << "Impossible" << endl;
    return 0;;
  }

  while (n % 2 == 0) {
    string x = s.substr(0, n / 2);
    string y{x};
    ranges::reverse(x);
    if (x != y) {
      cout << "1" << endl;
      return 0;
    }
    n /= 2;
  }
  cout << "2" << endl;
}
