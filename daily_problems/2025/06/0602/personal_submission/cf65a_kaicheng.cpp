/*
  https://codeforces.com/problemset/problem/65/A
  kaicheng
  2025-06-02
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define PII pair<int, int>

#include <iostream>
using namespace std;

signed main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  if (c == 0 && d > 0) {
    cout << "Ron" << '\n';
    return 0;
  }

  if (a == 0 && b > 0 && c > 0 && d > 0) {
    cout << "Ron" << '\n';
    return 0;
  }

  if (e == 0 && a > 0 && b > 0 && c > 0 && d > 0 && f > 0) {
    cout << "Ron" << '\n';
    return 0;
  }

  if (b * d * f > a * c * e) {
    cout << "Ron" << '\n';
    return 0;
  }

  cout << "Hermione" << '\n';
  return 0;
}