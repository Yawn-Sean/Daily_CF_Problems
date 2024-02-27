// Problem: B. Subway Pursuit
// Contest: Codeforces - Codeforces Round 507 (Div. 1, based on Olympiad of Metropolises)
// URL: https://codeforces.com/problemset/problem/1039/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <random>

#define FAST ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15)
#define Tsolve() int T; cin >> T; while (T --) solve()
using ll = long long;
using namespace std;
ll n, k;
int cnt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//-----------------------function-----------------------

bool ask(ll l, ll r) {
    cout << l << ' ' << r << endl;
    cout.flush();
    cnt ++;
    string s;
    cin >> s;
    return s[0] == 'Y';
}
void solve() {
    cin >> n >> k;
    ll l = 1, r = n;
    while (cnt < 4500) {
        if (r - l + 1 <= (k * 4 + 1)) {
            ll x = rng() % (r - l + 1) + l;
            if (ask(x, x)) break;
            l = max(l - k, 1ll);
            r = min(r + k, n);
        }
        else {
            auto mid = (l + r) >> 1;
            if (ask(l, mid)) {
                l = max(l - k, 1ll);
                r = min(mid + k, n);
            }
            else {
                l = max(mid + 1 - k, 1ll);
                r = min(r + k, n);
            }
        }
    }
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}
