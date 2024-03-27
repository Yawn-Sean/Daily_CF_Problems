#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    double ans = 0;
    int n, U;
    cin >> n >> U;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int left = 0, right = 0;
    while (left <= right) {
        while (right < n and a[right] <= a[left] + U) {
            ++right;
        }
        if (right - left < 2 or a[right - 1] > a[left] + U) {
            ++left;
            continue;
        }
        ans = max(ans, double(a[right - 1] - a[left + 1]) / (a[right - 1] - a[left]));
        ++left;
    }
    cout << (ans == 0 ? -1 : ans) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
