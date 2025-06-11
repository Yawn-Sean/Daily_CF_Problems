#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
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
    const int mod = 1e9+7;
    auto add = [&](int &x, int y)->void{
        (x += y) %= mod;
    };

    const int N = 2000;
    vector<vector<int>> f(N+1, vector<int>(N+1));
    f[0][0] = 1;
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j <= i; ++ j){
            if (j > 0){
                add(f[i+1][j-1], f[i][j]);
            }
            if (j < N){
                add(f[i+1][j+1], f[i][j]);
            }
        }
    }
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int cur = 0, mi = 1e9;
    for (auto &ch : s){
        if (ch == '(') cur += 1;
        else cur -= 1;
        fmin(mi, cur);
    }

    int res = 0;
    for (int i = 0; i <= n-m; ++ i){
        for (int j = 0; j <= i; ++ j){
            if (j+mi >= 0 && cur+j <= N){
                add(res, 1ll*f[i][j]*f[n-m-i][cur+j]%mod);
            }
        }
    }

    cout << res << "\n";
}
