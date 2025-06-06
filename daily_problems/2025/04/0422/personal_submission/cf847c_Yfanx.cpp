/* #pragma GCC optimize(2) */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  ll k;
  cin >> n >> k;
  if (k > 1LL * n * (n - 1) / 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  ll l = 0, r = n;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (1LL * mid * (mid - 1) / 2 < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  ll c = 1LL * l * (l - 1) / 2 > k ? l - 1 : l;

  if (1LL * c * (c - 1) / 2 == k) {
    for (int i = 0; i < c; i++)
      cout << '(';
    for (int i = 0; i < c; i++)
      cout << ')';
    for (int i = c; i < n; i++)
      cout << "()";
    return 0;
  }

  ll used = c;
  ll depth = c;
  k -= c * (c - 1) / 2;

  string ans;
  ans.reserve(2 * n);

  ans.append(c, '(');

  if (used < n && k > 0) {
    ll tempk = k;
    ll to_close = depth - tempk;
    ans.append(to_close, ')');
    depth -= to_close;

    ans.push_back('(');
    depth += 1;
    used += 1;
    k = 0;
  }

  ans.append(depth, ')');

  for (ll i = used; i < n; i++) {
    ans.append("()");
  }

  cout << ans << "\n";

  return 0;
}
