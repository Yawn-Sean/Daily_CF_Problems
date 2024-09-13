#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    vector <array<int,2>> segs;
    int res = 0;
    for (int i = 0, l, r; i < n; ++ i){
        cin >> l >> r;
        segs.push_back({l, r});
        res += 1ll*y*(r-l)%mod, res %= mod;
        res += x, res %= mod;
    }
    sort(segs.begin(), segs.end(), [&](array<int,2> &A, array<int,2> &B){
        return A[0] == B[0] ? A[1] < B[1] : A[0] < B[0];
    });

    multiset <int> st;
    st.insert(-1);
    for (int i = 0; i < n; ++ i){
        int l = segs[i][0], r = segs[i][1];
        auto it = st.lower_bound(l);
        if (it != st.begin()) -- it;
        if (it != st.begin() && l > *it && 1ll*y*(l - *it) < x){
            res += (1ll*y*(l - *it)%mod - x)%mod;
            res = (res%mod + mod)%mod;
            auto p = it;
            it = st.lower_bound(l);
            if (it != st.begin()) -- it;
            st.erase(p);
        }
        st.insert(r);
    }

    cout << res << "\n";
}
