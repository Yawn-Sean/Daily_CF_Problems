#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> pts(n);
    for (auto &p : pts) cin >> p.first >> p.second;

    unordered_set<long long> st;
    st.reserve(n * 2);
    auto encode = [&](long long x, long long y) {
        return (x << 32) ^ (y & 0xffffffff);
    };
    for (auto &[x, y] : pts) st.insert(encode(x, y));

    auto has = [&](long long x, long long y) {
        return st.find(encode(x, y)) != st.end();
    };

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {

            long long x1 = pts[i].first,  y1 = pts[i].second;
            long long x2 = pts[j].first,  y2 = pts[j].second;

            long long dx = x2 - x1;
            long long dy = y2 - y1;
            if (has(x1 + dx - dy, y1 + dx + dy) &&
                has(x1 - dy,        y1 + dx))
                ans++;
            if (has(x1 + dy,        y1 - dx) &&
                has(x1 + dx + dy,   y1 + dy - dx))
                ans++;
        }
    }

    cout << ans / 4;
    return 0;
}
