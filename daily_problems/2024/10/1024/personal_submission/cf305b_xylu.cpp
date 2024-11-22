#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solveB() {
    ll p, q;
    int n;
    cin >> p >> q >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    vector<ll> target;
    while (q) {
        target.push_back(p / q);
        p %= q;
        swap(p, q);
    }

    if (n > 1 && a[n-1] == 1) {
        a.pop_back();
        n--, a[n-1]++;
    }

    if (a != target) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    solveB();
    return 0;
}
