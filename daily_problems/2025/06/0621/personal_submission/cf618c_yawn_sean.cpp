#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);
    for (auto &[x, y]: pts)
        cin >> x >> y;
    
    auto area = [&] (int i, int j, int k) -> long long {
        int dx1 = pts[j].first - pts[i].first;
        int dy1 = pts[j].second - pts[i].second;
        int dx2 = pts[k].first - pts[i].first;
        int dy2 = pts[k].second - pts[i].second;
        return abs(1ll * dx1 * dy2 - 1ll * dx2 * dy1);
    };

    int a = 0, b = 1, chosen = -1;
    for (int i = 0; i < n; i ++) {
        if (area(a, b, i) && (chosen == -1 || area(a, b, i) < area(a, b, chosen))) {
            chosen = i;
        }
    }

    a = 0, b = chosen, chosen = -1;
    for (int i = 0; i < n; i ++) {
        if (area(a, b, i) && (chosen == -1 || area(a, b, i) < area(a, b, chosen))) {
            chosen = i;
        }
    }

    cout << a + 1 << ' ' << b + 1 << ' ' << chosen + 1;

    return 0;
}