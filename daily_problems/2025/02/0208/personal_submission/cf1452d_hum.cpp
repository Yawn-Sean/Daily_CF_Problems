#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int mod{998244353};
  long long a{}, b{1};
  for (int i = 0; i < n; i++) {
    a += b;
    a %= mod;
    swap(a, b);
  }
  int rev2 = (mod + 1) / 2;
  for (int i = 0; i < n; i++) {
    a = (a * rev2) % mod;
  }
  cout << a;
}
