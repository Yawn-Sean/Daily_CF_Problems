#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
using f64 = long double;
const f64 radio = 1 - (sqrt(f64(5)) - 1) / 2;

void solve(){
    const int inf = 1e9;
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> f1(a+1,vector<int>(2, inf)), f2(a+1,vector<int>(2, inf));
    vector <int> h(n+1);
    for (int i = 1; i <= n; ++ i) cin >> h[i];

    f1[0][0] = f1[0][1] = 0;
    for (int i = 1,all=0; i <= n; ++ i){
        for (int j = 0; j <= a; ++ j){
            int rare[] = {a-j, b-(all-j)};
            for (int v = 0; v < 2; ++ v){  // f[i][j][u] 第i堵墙，用了j个颜料a，最后一次染红/绿 色
                if (f1[j][v] == inf) continue;  // 枚举上一个状态 f1[j][v]
                for (int u = 0; u < 2; ++ u){  // 下一个状态是 f2[nxt][u]
                    int nxt = u == 0 ? j+h[i] : j;
                    if (rare[u] >= h[i] && nxt<=a){
                        fmin(f2[nxt][u], f1[j][v] + (u!=v)*min(h[i], h[i-1]));
                    }
                }
            }
        }
        all += h[i];
        f1 = f2;
        for (int j = 0; j <= a; ++ j){
            for (int u = 0; u < 2; ++ u){
                f2[j][u] = inf;
            }
        }
    }
    int res = inf;
    for (int i = 0; i <= a; ++ i){
        for (int u = 0; u < 2; ++ u){
            fmin(res, f1[i][u]);
        }
    }

    if (res == inf) cout << -1 << "\n";
    else cout << res << "\n";
}
