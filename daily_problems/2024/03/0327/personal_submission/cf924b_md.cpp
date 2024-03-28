#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u;
    cin >> n >> u;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    double ret = -1.0;
    for (auto ei_it = begin(s); ei_it != end(s); ++ei_it) {
        int ei = *ei_it;
        auto ej = *next(ei_it);
        auto ek_it = s.upper_bound(ei + u);
        if (ek_it == begin(s)) {
            continue;
        }

        ek_it = prev(ek_it);
        if (ek_it == ei_it || *ek_it == ej) {
            continue;
        }

        auto ek = *ek_it;
        ret = max(ret, (0.0 + ek - ej) / (ek - ei));
    }

    if (ret < 0) {
        cout << -1;
    } else {
        cout << fixed << setprecision(9) << ret << endl;
    }

    return 0;
}