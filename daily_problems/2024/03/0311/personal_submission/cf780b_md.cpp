#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr double oo = 1e18;

void solve() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    auto check = [&](double time) -> bool {
        double maxleft = -oo;
        double minright = oo;
        for (int i = 0; i < n; ++i) {
            double left = x[i] - v[i] * time;
            double right = x[i] + v[i] * time;
            maxleft = max(maxleft, left);
            minright = min(minright, right);
        }

        return maxleft <= minright;
    };

    double start = -oo;
    double end = oo;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (start + end) / 2;
        if (check(mid)) {
            end = mid;
        } else {
            start = mid;
        }
    }

    cout << fixed << setprecision(12) << start << endl;
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