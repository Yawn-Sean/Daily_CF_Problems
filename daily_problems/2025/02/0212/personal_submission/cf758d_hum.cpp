#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string k;
  cin >> n >> k;
  int j{};
  long long bn{1}, res{};
  for (int i = k.size() - 1; i >= 0; i = j - 1) {
    j = i + 1;
    long long cur{};
    long long base = 1;
    while (j - 1 >= 0 && cur + base * (k[j - 1] - '0') < n) {
      cur += base * (k[j - 1] - '0');
      base *= 10;
      --j;
      if (base > 1e9) {
        break;
      }
    }
    while (j < i && k[j] == '0') {
      j++;
    }
    res += cur * bn;
    bn *= n;
  }
  cout << res << '\n';
}
