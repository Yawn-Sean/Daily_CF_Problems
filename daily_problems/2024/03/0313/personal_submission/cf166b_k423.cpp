/**
 * Created by 5cm/s on 2024/01/05 10:33:15.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using i64 = int64_t;

struct vec {
    i64 x, y;

    vec(i64 x = 0, i64 y = 0) : x(x), y(y) {}

    vec &operator-=(const vec &p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    vec operator-(const vec &p) const { return {x - p.x, y - p.y}; }

    i64 operator^(const vec &p) const { return x * p.y - y * p.x; }

    i64 abs2() const { return x * x + y * y; }

    long double abs() const { return sqrt(abs2()); }

    bool operator<(const vec &p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

vector<vec> convex_hull(vector<vec> &points) {
    int n = points.size();
    assert(n >= 3);
    swap(points[0], *min_element(points.begin(), points.end()));
    auto cmp = [&](vec p1, vec p2) -> bool {
        i64 c = p1 ^ p2;
        if (c == 0) return p1.abs2() < p2.abs2();
        return c < 0;
    };

    sort(points.begin() + 1, points.end(), [&](vec &p1, vec &p2) -> bool {
        return cmp(p1 - points[0], p2 - points[0]);
    });
    int k = points.size() - 1;
    while (k > 1 && ((points[k - 1] - points[0]) ^ (points[k] - points[0])) == 0) k--;
    reverse(points.begin() + k, points.end());
    vector<vec> ret = {points[0]};
    for (int i = 1; i < n; ++i) {
        while (ret.size() >= 2 && cmp(points[i] - ret.rbegin()[0], ret.rbegin()[0] - ret.rbegin()[1])) {
            ret.pop_back();
        }
        ret.emplace_back(points[i]);
    }
    return ret;
}


void elysia() {
    int size_a, size_b;
    cin >> size_a;
    vector<vec> A(size_a), points;
    for (auto &[x, y]: A) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    cin >> size_b;
    vector<vec> B(size_b);
    for (auto &[x, y]: B) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    vector<vec> ch = convex_hull(points);

    set<vec> sb(itr(B));
    for (auto &p: ch) if (sb.count(p)) return NO();
    YES();
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