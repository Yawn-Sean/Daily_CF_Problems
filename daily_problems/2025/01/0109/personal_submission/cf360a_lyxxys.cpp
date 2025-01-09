#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 1e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector <array<int,4>> opts(m);
    vector <int> ans(n+1, inf_int), diff(n+1);

    for (auto &it : opts){
        cin >> it[0] >> it[1] >> it[2] >> it[3];
    }

    for (auto &it : opts){
        int l = it[1], r = it[2];
        if (it[0] == 1){
            int d = it[3];
            for (int i = l; i <= r; ++ i){
                diff[i] += d;
            }
        } else {
            int m = it[3];
            for (int i = l; i <= r; ++ i){
                fmin(ans[i], m-diff[i]);
            }
        }
    }

    vector <int> B = ans;
    for (auto &it : opts){
        int l = it[1], r = it[2];
        if (it[0] == 1){
            int d = it[3];
            for (int i = l; i <= r; ++ i){
                B[i] += d;
            }
        } else {
            int m = it[3], v = -inf_int;
            for (int i = l; i <= r; ++ i){
                fmax(v, B[i]);
            }
            if (v != m){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++ i){
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
