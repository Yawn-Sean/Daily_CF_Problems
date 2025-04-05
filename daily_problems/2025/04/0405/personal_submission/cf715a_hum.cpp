#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << 2 << "\n";
  for (long long i = 2; i <= n; i++) {
    cout << (i + 1) * (i + 1) * i - i + 1 << "\n";
  }
}
