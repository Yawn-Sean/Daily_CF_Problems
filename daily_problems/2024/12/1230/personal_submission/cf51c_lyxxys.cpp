#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    auto div2 = [&](int x)->string{
        if (x%2) return to_string(x/2) + ".500000";
        else return to_string(x/2) + ".000000";
    };

    int n;
    cin >> n;
    vector <int> xs(n);
    for (auto &x : xs){
        cin >> x;
    }
    sort(xs.begin(), xs.end());

    if (n == 1 || n == 2){
        cout << 0 << "\n";
        cout << fixed << setprecision(6);
        cout << 1.0*xs[0] << " " << 1.0*xs[n-1] << " " << 1.0*xs[n-1] << "\n";
        return;
    }
    
    int l = 0, r = n-1;

    int idx_mid = 1, ans = 2e9;
    while (l+1 < r){
        int v = max({xs[l]-xs[0], xs[r-1]-xs[l+1], xs[n-1]-xs[r]});
        if (ans > v){
            ans = v;
            idx_mid = l+1;
        }

        if (xs[l+1]-xs[0] <= xs[n-1]-xs[r-1]) l += 1;
        else r -= 1;

        v = max({xs[l]-xs[0], xs[r-1]-xs[l+1], xs[n-1]-xs[r]});
        if (ans > v){
            ans = v;
            idx_mid = l+1;
        }
    }
    cout << div2(ans) << "\n";
    cout << div2(2*xs[0]+ans) << " " << div2(2*xs[idx_mid]+ans) << " " << div2(2*xs[n-1]-ans) << "\n";
}
