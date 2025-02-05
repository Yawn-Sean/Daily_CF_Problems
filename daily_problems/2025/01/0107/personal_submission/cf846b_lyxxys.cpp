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
    int n, k, w;
    cin >> n >> k >> w;
    vector <int> ts(k);
    int all = 0;
    for (auto &x : ts){
        cin >> x;
        all += x;
    }
    sort(ts.begin(), ts.end());

    int ma = 0;
    for (int i = 0; i <= n; ++ i){
        if (all*i > w) break;
        int val = (k+1)*i, wi = w - all*i;
        for (auto &x : ts){
            if (wi > (n-i)*x){
                wi -= (n-i)*x;
                val += n-i;
            } else {
                val += wi/x;
                break;
            }
        }
        fmax(ma, val);
    }

    cout << ma << "\n";
}
