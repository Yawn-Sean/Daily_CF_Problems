#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 1e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int,4>> fli(m);
    vector <i64> Pr(m, inf_i64), Sf(m, inf_i64);

    for (auto &it : fli){
        cin >> it[0] >> it[1] >> it[2] >> it[3];
        it[1] -= 1, it[2] -= 1;
    }

    sort(fli.begin(), fli.end(), [&](auto &u, auto &v){
        return u[0] < v[0];
    });

    i64 all = 0;
    vector <int> mins(n);
    for (int i = 0, cnt = 0; i < m; ++ i){
        if (fli[i][2] == -1){
            int who = fli[i][1], cost = fli[i][3];
            if (mins[who] == 0) cnt += 1, mins[who] = cost, all += cost;
            else {
                if (cost < mins[who]){
                    all -= mins[who]-cost;
                    mins[who] = cost;
                }
            }
        }
        if (cnt == n) Pr[i] = all;
    }

    fill(mins.begin(), mins.end(), 0), all = 0;
    for (int i = m-1,cnt = 0; i >= 0; -- i){
        if (fli[i][1] == -1){
            int who = fli[i][2], cost = fli[i][3];
            if (mins[who] == 0) cnt += 1, mins[who] = cost, all += cost;
            else {
                if (cost < mins[who]){
                    all -= mins[who]-cost;
                    mins[who] = cost;
                }
            }
        }
        if (cnt == n) Sf[i] = all;
    }

    i64 res = inf_i64;
    for (int i = 0, j = -1; i < m; ++ i){
        while (j+1 < m && (j < i || fli[j][0]-fli[i][0] <= k)){
            j += 1;
        }
        if (fli[j][0]-fli[i][0] > k){
            fmin(res, Pr[i]+Sf[j]);
        }
    }

    if (res == inf_i64) cout << -1 << "\n";
    else cout << res << "\n";
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
