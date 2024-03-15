/**
 * Created by 5cm/s on 2024/03/15 11:00:47.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using pii = pair<int, int>;
using i64 = int64_t;

void elysia() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto &[x, y]: a) cin >> x >> y;
    sort(itr(a));
    map<pii, int> cnt;
    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int x = a[i].first - a[j].first, y = a[i].second - a[j].second;
            ans += cnt[pii{x, y}]++;
        }
    }
    cout << ans / 2 << endl;
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
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
