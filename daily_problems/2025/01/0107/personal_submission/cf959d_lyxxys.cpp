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
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A) cin >> x;

    const int tot = 2e6;
    vector <int> prms;
    vector <int> vis(tot+1), used(tot+1);
    for (int i = 2; i <= tot; ++ i){
        if (!vis[i]) prms.push_back(i);
        for (auto &y : prms){
            if (i*y > tot) break;
            vis[i*y] = 1;
            if (i%y == 0) break;
        }
    }

    auto chk = [&](int x)->bool{
        vector <int> ins;
        for (i64 i = 2; i*i <= x; ++ i){
            if (x%i == 0){
                if (used[i]) return false;
                ins.push_back(i);
                while (x%i == 0) x /= i;
            }
        }
        if (x > 1 && used[x]) return false;

        if (x > 1) ins.push_back(x);
        for (auto &y : ins) used[y] = 1;
        return true;
    };
    
    int j = 0;
    bool jg = 0, big = 0;
    vector <int> ans;
    for (auto &x : A){
        if (!jg){
            if (chk(x)) ans.push_back(x);
            else jg = 1;   
        }
        if (jg){
            if (!big){
                int y = x+1;
                while (!chk(y)) y += 1;
                ans.push_back(y);
                big = 1;
            } else {
                while (used[prms[j]]) j += 1;
                used[prms[j]] = 1;
                ans.push_back(prms[j]);
            }
        }
    }

    assert(ans.size() == n);
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
