#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ld = long double;
    int x, k, p;
    cin >> x >> k >> p;
    const ld p1 = (ld)p / 100, p2 = 1-p1;
    vector<vector<ld>> f(k+1, vector<ld>(k+1));
    // f[i][j] 表示第 i 次操作欠了 j 次+1 操作时期望的后缀0 个数
    for (int i = 0; i <= k; ++ i){
        int v = x+i;
        v &= -v;
        f[0][i] = 32 - __builtin_clz(v) - 1;
    }

    for (int i = 0; i < k; ++ i){
        for (int j = 0; j <= k; ++ j){
            if (2*j <= k) f[i+1][j*2] = p1 * (f[i][j] + 1);
            if (j > 0) f[i+1][j-1] += p2 * f[i][j];
        }
    }

    cout << fixed << setprecision(15) << f[k][0] << "\n";
}
