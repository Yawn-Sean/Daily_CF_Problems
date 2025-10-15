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

typedef array<int, 2> vec;
vec dir(vec x1, vec x2) {return {x2[0] - x1[0], x2[1] - x1[1]};}
bool sgn(vec x) {return x[0] > 0 || (x[0] == 0 && x[1] > 0);}
long long cross(vec x1, vec x2) {return 1ll * x1[0] * x2[1] - 1ll * x1[1] * x2[0];}
long long dot(vec x1, vec x2) {return 1ll * x1[0] * x2[0] + 1ll * x1[1] * x2[1];}

vector<vec> convex_hull(vector<vec> pts) {
    sort(pts.begin(), pts.end());
    vector<vec> up, down;
    
    for (auto &pt: pts) {
        while (up.size() > 1) {
            auto v1 = up[up.size() - 2], v2 = up[up.size() - 1];
            if (cross(dir(v1, v2), dir(v1, pt)) >= 0) up.pop_back();
            else break;
        }
        up.emplace_back(pt);
    }

    for (auto &pt: pts) {
        while (down.size() > 1) {
            auto v1 = down[down.size() - 2], v2 = down[down.size() - 1];
            if (cross(dir(v1, v2), dir(v1, pt)) <= 0) down.pop_back();
            else break;
        }
        down.emplace_back(pt);
    }

    down.pop_back();
    down.insert(down.end(), up.rbegin(), up.rend());
    down.pop_back();
    return down;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<vec> pts(n);
        for (auto &[x, y]: pts) cin >> x >> y;

        auto cv = convex_hull(pts);
        set<vec> chosen(cv.begin(), cv.end());

        map<vec, int> pos;
        for (int i = 0; i < n; i ++)
            pos[pts[i]] = i;
        
        auto check = [&] (int x1, int y1, int x2, int y2, int x3, int y3) -> bool {
            int dx1 = x2 - x1, dy1 = y2 - y1;
            int dx2 = x3 - x1, dy2 = y3 - y1;
            return 1ll * dx1 * dy2 > 1ll * dx2 * dy1;
        };

        if (cv.size() == n) cout << -1 << '\n';
        else {
            for (int idx = 0; idx < n; idx ++) {
                if (chosen.find(pts[idx]) == chosen.end()) {
                    auto [x, y] = pts[idx];

                    for (int i = 2; i < cv.size(); i ++) {
                        auto [x1, y1] = cv[0];
                        auto [x2, y2] = cv[i - 1];
                        auto [x3, y3] = cv[i];

                        if (check(x1, y1, x2, y2, x, y) &&
                            check(x2, y2, x3, y3, x, y) && 
                            check(x3, y3, x1, y1, x, y)) {
                            cout << idx + 1 << ' ' << pos[{x1, y1}] + 1 << ' ' << pos[{x2, y2}] + 1 << ' ' << pos[{x3, y3}] + 1 << '\n';
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0;
}