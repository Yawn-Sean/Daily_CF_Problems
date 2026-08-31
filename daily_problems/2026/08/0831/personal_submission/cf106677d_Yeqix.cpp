#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve(i64 s, i64 k) {
    if (s == 0 && k == 0) {
        return;
    }

    if (k == 1) {
        cout << s << '\n';
        return;
    }

    k--;
    i64 pre = (1 + 2 * s - 1) * s / 2;

    if (k <= pre) {
        i64 l = 1, r = s;
        while (l <= r) {
            i64 mid = (l + r) >> 1;
            if ((4 * s - 2 * mid) * mid / 2 < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        k -= (4 * s - 2 * r) * r / 2;
        if (k == 0) {
            cout << s << '\n';
            return;
        }
        i64 len = 2 * s - 1 - r;
        if (k % 2 == 0) {
            cout << r + 1 << "\n";
        } else {
            cout << r + 1 + k / 2 << "\n";
        }
    } else {
        k -= pre;

        if (k & 1) {
            cout << s + (k + 2 * s - 1) / (2 * s) << "\n";
        } else {
            k -= (k - 2) / (2 * s) * (2 * s) - 1;
            cout << k / 2 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 s, k;
    while (cin >> s >> k) {
        solve(s, k);
    }
    return 0;
}