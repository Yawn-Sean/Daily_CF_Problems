#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, z, u, t;
};
Point operator - (Point a, Point b){
    return {a.x-b.x, a.y-b.y, a.z-b.z, a.u-b.u, a.t-b.t};
}
int doting(Point a, Point b){
    return a.x*b.x + a.y*b.y + a.z*b.z + a.u*b.u + a.t*b.t;
}

void solve(){
    int n;
    cin >> n;
    vector <Point> dots(n);
    for (auto &it : dots) cin >> it.x >> it.y >> it.z >> it.u >> it.t;
    if (n > 100){
        cout << 0 << "\n";
        return;
    }
    vector <int> ans;

    for (int i = 0; i < n; ++ i){
        bool jg = true;
        for (int j = 0; j < n && jg; ++ j){
            if (j == i) continue;
            for (int p = 0; p < n && jg; ++ p){
                if (p == i || p == j) continue;
                if (doting(dots[j]-dots[i], dots[p]-dots[i]) > 0){
                    jg = false;
                }
            }
        }
        if (jg) ans.push_back(i+1);
    }

    cout << ans.size() << "\n";
    for (auto &x : ans) cout << x << "\n";
}
