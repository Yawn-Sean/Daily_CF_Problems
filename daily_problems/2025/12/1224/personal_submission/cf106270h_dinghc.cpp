#include <bits/stdc++.h>
 
using namespace std;
constexpr long long INF = 1e15;
constexpr int A = 1e6;
constexpr int N = 2e5;
array<int, 2> fs[N];
int lpf[A + 1];
vector<int> pr;
 
auto init = [] {
    for (int i = 2; i <= A; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= A; ++j) {
            lpf[i * pr[j]] = pr[j];
            if (pr[j] == lpf[i]) break;
        }
    }
    return 0;
}();
 
array<int, 2> facz(int x) {
    array<int, 2> res{};
    while (x > 1) {
        int p = lpf[x];
        res[p & 1] += p;
        x /= p;
    }
    return res;
}
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            fs[i] = facz(x);
        }
        sort(fs, fs + n, [] (auto& x, auto& y) -> bool {
            return x[1] - x[0] < y[1] - y[0];
        });
        vector<long long> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + fs[i][0];
        }
        long long ans = INF, cur = 0;
        for (int i = 0; i < n; i++) {
            cur += fs[i][1];
            if (i + 1 >= a && n - i - 1 >= b) {
                ans = min(ans, cur + suf[i + 1]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

