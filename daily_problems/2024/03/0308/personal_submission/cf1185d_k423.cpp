/**
 * Created by 5cm/s on 2024/03/08 11:50:28.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using pii = pair<int, int>;

void elysia() {
    int n;
    cin >> n;
    vector<pii> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    ranges::sort(p);
    multiset<int> S;
    for (int i = 0; i + 1 < n; ++i) {
        S.emplace(p[i + 1].first - p[i].first);
    }
    for (int i = 0; i < n; ++i) {
        if (i) S.extract(p[i].first - p[i - 1].first);
        if (i + 1 < n) S.extract(p[i + 1].first - p[i].first);
        if (i && i + 1 < n) S.insert(p[i + 1].first - p[i - 1].first);
        if (S.empty() || *S.begin() == *S.rbegin()) {
            cout << p[i].second << endl;
            return;
        }
        if (i) S.insert(p[i].first - p[i - 1].first);
        if (i + 1 < n) S.insert(p[i + 1].first - p[i].first);
        if (i && i + 1 < n) S.extract(p[i + 1].first - p[i - 1].first);
    }
    cout << -1 << endl;
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
