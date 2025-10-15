#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> notes(m);
    for (auto &[x, y]: notes) cin >> x >> y;

    int ans = max(notes[0].first - 1 + notes[0].second,
                  n - notes.back().first + notes.back().second);

    for (int i = 1; i < m; i ++) {
        auto [d1, h1] = notes[i - 1];
        auto [d2, h2] = notes[i];
        if (abs(h1 - h2) > d2 - d1) return cout << "IMPOSSIBLE", 0;
        ans = max(ans, (h1 + h2 + d2 - d1) / 2);
    }

    cout << ans;

    return 0;
}
