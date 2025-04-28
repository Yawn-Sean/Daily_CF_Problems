#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  long long res{};
  for (int i = 0; i < n; i++) {
    if (s[i] == '@') {
      int x{};
      for (int j = i - 1; j >= 0 && s[j] != '.' && s[j] != '@'; j--) {
        if (isalpha(s[j])) {
          x++;
        }
      }
      int y{};
      for (int j = i + 1; j < n && s[j] != '.' && s[j] != '@' && s[j] != '_'; j++) {
        y++;
      }
      if (y == 0 || s[i + y + 1] != '.') {
        continue;
      }
      int z = 0;
      for (int j = i + y + 2; j < n && isalpha(s[j]); j++) z++;
      res += 1ll * x * z;
    }
  }
  cout << res << '\n';
}
