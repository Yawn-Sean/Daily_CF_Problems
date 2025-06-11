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

    i64 b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    set <int> st;
    for (int i = 0, x; i < m; ++ i){
        cin >> x;
        st.insert(x);
    }

    if (abs(b1) > l){
        cout << 0 << "\n";
        return;
    }

    int ans = 0;   // ans equals -1 standing for infinite
    if (b1 == 0){
        ans = st.count(0) ? 0 : -1;
    } else if (q == 0){
        if (st.count(0)){
            ans = !st.count(b1);
        } else {
            ans = -1;
        }
    } else if (abs(q) == 1){
        if (q == 1){
            ans = st.count(b1) ? 0 : -1;
        } else {
            ans = st.count(b1) && st.count(-b1) ? 0 : -1;
        }
    } else {
        int sm = 0;
        i64 cur = b1;
        while (abs(cur) <= l){
            sm += 1;
            if (st.count(cur)) sm -= 1;
            cur *= q;
        }
        ans = sm;
    }

    if (ans == -1) cout << "inf\n";
    else cout << ans << "\n";
}
