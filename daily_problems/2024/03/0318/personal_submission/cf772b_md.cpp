#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> points;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.push_back(points[0]);
    points.push_back(points[1]);
    n += 2;

    auto dist = [](auto a, auto b) -> double {
        return sqrt((a.first - b.first) * (a.first - b.first) + 
                    (a.second - b.second) * (a.second - b.second));
    };

    double ret = std::numeric_limits<double>::max();
    for (int i = 0; i + 2 < n; ++i) {
        auto d1 = dist(points[i], points[i + 1]);
        auto d2 = dist(points[i + 1], points[i + 2]);
        auto d3 = dist(points[i], points[i + 2]);
        double p = (d1 + d2 + d3) / 2.0;
        double area = sqrt(p * (p - d1) * (p - d2) * (p - d3));
        ret = min(ret, area / d3);
    }

    cout << fixed << setprecision(10) << ret << "\n";
    return 0;
}