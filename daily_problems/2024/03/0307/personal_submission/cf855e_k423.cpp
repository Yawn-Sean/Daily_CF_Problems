/**
 * Created by 5cm/s on 2024/03/07 10:30:30.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using i64 = int64_t;
int A[60], radix;
i64 dp[9][60][1 << 10][2];
i64 dfs(int pos, int pre, bool is_valid, bool is_limit) {
    if (pos < 0) return int(is_valid && pre == 0);
    if (__builtin_popcount(pre) > pos + 1) return 0;
    i64 &val = dp[radix - 2][pos][pre][is_valid];
    if (!is_limit && val >= 0) return val;
    i64 ret = 0;
    for (int x = 0; x < radix; ++x) {
        if (!is_limit || x <= A[pos]) {
            int nxt = pre;
            if (is_valid || x) nxt ^= 1 << x;
            ret += dfs(pos - 1, nxt, is_valid || x > 0, is_limit && x == A[pos]);
        }
    }
    if (!is_limit) val = ret;
    return ret;
}

i64 f(i64 x) {
    int pos = 0;
    while (x) A[pos++] = x % radix, x /= radix;
    return dfs(pos - 1, 0, false, true);
}

void elysia() {
    i64 L, R;
    cin >> radix >> L >> R;
    cout << f(R) - f(L - 1) << endl;
}

int main() {
#ifdef MEGURINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp, -1, sizeof dp);

    int T = 1;
    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
