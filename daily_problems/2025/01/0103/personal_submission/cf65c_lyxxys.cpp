#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < eps ? -1 : x >= eps);
}

void solve(){
    using ary3 = array<i64,3>;
    int n;
    i64 vi, vj;
    cin >> n;
    auto Dis = [&](f64 x, f64 y, f64 z)->f64{
        return sqrtl(x*x + y*y + z*z);
    };
    auto Dis_p = [&](auto u, auto v)->f64{
        return Dis(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
    };

    vector <ary3> ps(n+1);
    ary3 p;
    for (auto &it : ps){
        cin >> it[0] >> it[1] >> it[2];
    }
    cin >> vi >> vj;
    cin >> p[0] >> p[1] >> p[2];

    bool jg = 0;
    f64 last = 0;
    int mark;
    for (int i = 1; i <= n; ++ i){
        last += Dis_p(ps[i], ps[i-1]);
        f64 d = Dis_p(ps[i], p);
        if (jgs(d/vi - last/vj) <= 0){
            jg = 1, mark = i;
            last -= Dis_p(ps[i], ps[i-1]);
            break;
        }
    }

    if (!jg) return void(cout << "NO\n");

    auto move_p = [&](ary3 u, ary3 v, f64 mid)->array<f64,3>{
        array<f64,3> ds = {v[0]-u[0], v[1]-u[1], v[2]-u[2]};
        for (int i = 0; i < 3; ++ i) ds[i] *= mid / 1000, ds[i] += u[i];
        return ds;
    };
    cout << "YES\n";

    f64 lo = 0, hi = 1000, ans = 0;
    for (int i = 0; i < 200; ++ i){
        f64 mid = (lo+hi) / 2;
        auto j = move_p(ps[mark-1], ps[mark], mid);
        f64 d1 = Dis_p(p, j), d2 = last + Dis_p(ps[mark-1], j);
        if (jgs(d1/vi - d2/vj) <= 0) hi = mid;
        else lo = mid;
        ans = d1/vi;
    }

    auto ans_p = move_p(ps[mark-1], ps[mark], lo);
    cout << fixed << setprecision(10);
    cout << ans << "\n";
    cout << ans_p[0] << " " << ans_p[1] << " " << ans_p[2] << "\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
