#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 A, S, L, R;
    cin >> A >> S >> L >> R;

    i64 ans = (A == S);
    for (i64 len = 2; len <= 100000; len++) {
        i64 res = S - len * A;
        for (i64 d = 1; L + (len - 1) * d <= R; d++) {
            i64 v = (len - 1) * d * len / 2;
            if ((res - v) % (len * d) == 0) {
                i64 cnt = (res - v) / (len * d);
                if (cnt <= 0 && cnt > -len && A + cnt * d >= L && A + (len - 1 + cnt) * d <= R) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}