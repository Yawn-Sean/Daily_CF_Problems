#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> pts;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < size(pts); ++i) {
        for (int j = i + 1; j < size(pts); ++j) {
            mp[{pts[i].first + pts[j].first, pts[i].second + pts[j].second}]++;
        }
    }

    long long ret{};
    for (auto[_, cnt] : mp) {
        ret += cnt * (cnt - 1) / 2;
    }

    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}