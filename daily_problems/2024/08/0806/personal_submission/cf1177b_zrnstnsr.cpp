#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;
long long a[] = { 1, 10, 190, 2890, 38890, 488890, 5888890, 68888890, 788888890, 8888888890, 98888888890, 1088888888890, 11888888888890 };
long long t[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};

void solve() {
    long long k;
    int m = sizeof(a) / sizeof(long long);
    cin >> k;
    auto p = upper_bound(a, a + m, k) - 1;
    auto d = p - a;
    auto n = (k - *p) / (d + 1) + t[d];
    auto i = (k - *p) % (d + 1);
    cout << to_string(n)[i] << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
