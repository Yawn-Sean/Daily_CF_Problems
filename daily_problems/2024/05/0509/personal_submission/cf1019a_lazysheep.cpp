#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
 
constexpr i64 inf = 1E16;
 
int cost[3010], p[3010];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1)     x++;
        p[i] = a, cost[i] = b;
    }
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 1);
    ranges::sort(seq, [&](int i, int j) {
        return cost[i] > cost[j];
    }); 
    i64 ans = inf;
    vector<int> cnt(m + 1);
    vector<bool> st(n + 1);
    for (int num = max(x - 1, 0); num <= n - 1; num++) {
        i64 res = 0; int cntv = 0;
        for (int i : seq) {          
            if (p[i] == 1)  cntv++;
            else {
                if (cnt[p[i]] < num) {
                    cnt[p[i]]++;
                    st[i] = 1;
                }
                else {
                    cntv++;
                    res += cost[i];
                }
            }
        }
        for (int i = n - 1; i; i--) {
            if (cntv <= num && st[seq[i]]) {
                cntv++;
                res += cost[seq[i]];
            }
            cnt[p[i]] = 0, st[seq[i]] = 0;
        }
        ans = min(ans, res);
    }
 
    cout << ans << '\n';
 
    return 0;
}
