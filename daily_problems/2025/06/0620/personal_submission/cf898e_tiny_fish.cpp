#include <bits/stdc++.h>

// #define dv(x) do { cout << #x << ": "; for(auto &_v : x) cout << _v << ' '; cout << '\n'; } while(0)
#define dv(x) void(0)

using ll = long long;

using std::cin, std::cout, std::ios;

ll _sqrt(ll x) {
    ll l = 0, r = x;
    while(l < r) {
        ll m = (l + r + 1) >> 1;
        if(m * m <= x) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

bool check(ll x) {
    auto l = _sqrt(x);
    return l * l == x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    std::vector <ll> a(n); for(auto &i : a) cin >> i;
    std::vector <ll> b; int sqr = 0;
    std::vector <ll> c;

    std::sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(sqr < n / 2 and check(a[i]))
            sqr ++, c.emplace_back(a[i]);
        else
            b.emplace_back(a[i]);
    }

    ll ans = 0;
    std::sort(b.begin(), b.end());

    dv(a); dv(b); dv(c);

    if(sqr < n / 2) {
        std::vector <ll> val;

        for(int i = 0; i < (int) b.size(); i++) {
            auto l = _sqrt(b[i]);
            auto L = l * l, R = (l + 1) * (l + 1);
            val.emplace_back(std::min(b[i] - L, R - b[i]));
        }

        std::sort(val.begin(), val.end());
        dv(val);

        for(int i = 0; i < n / 2 - sqr; i++) {
            ans += val[i];
        }
    } else {
        for(int i = 0; i < (int) b.size(); i++) {
            if(check(b[i])) {
                ans += 1 + (b[i] == 0);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}