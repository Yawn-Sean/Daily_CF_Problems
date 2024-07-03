#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+5, inf = 1e9;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll sum = a * b;
    ll be = round(cbrt(sum));

    if (be*be*be == sum && a%be==0 && b%be==0) cout << "Yes\n";
    else cout << "No\n";
}
