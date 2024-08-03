#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 200000;
pair<int, int> a[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> b(n*2);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
        b[i<<1] = a[i].first;
        b[(i<<1)+1] = a[i].second;
    }

    ranges::sort(b);
    auto rng = ranges::unique(b);
    b.erase(rng.begin(), rng.end());
    vector<int> c;
    for (int i = 1; i < b.size(); i++) {
        if (b[i] - b[i - 1] > 1) {
            c.push_back((b[i] + b[i - 1]) / 2);
        }
    }
    copy(c.begin(), c.end(), back_inserter<>(b));
    ranges::sort(b);

    int mx = b.size() - 1;
    vector<int> diff(mx + 2, 0);
    for (int i = 0; i < n; i++) {
        auto& [a0, a1] = a[i];
        a0 = ranges::lower_bound(b, a0) - b.begin();
        a1 = ranges::lower_bound(b, a1) - b.begin();
        diff[a0]++;
        diff[a1 + 1]--;
    }

    vector<int> sums(mx + 3, 0);
    sums[1] = diff[0] > 1 ? 1 : 0;
    for (int i = 1; i <= mx + 1; i++) {
        diff[i] += diff[i - 1];
        sums[i + 1] = sums[i] + (diff[i] > 1 ? 1 : 0);
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        auto& [a0, a1] = a[i];
        if (sums[a1 + 1] - sums[a0] == a1 + 1 - a0) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}

