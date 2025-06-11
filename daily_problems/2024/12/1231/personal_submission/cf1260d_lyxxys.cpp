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
    int m, n, k, tar;
    cin >> m >> n >> k >> tar;
    vector <int> A(m), diff(n+1), ls, rs, ds;
    for (auto &x : A){
        cin >> x;
    }
    for (int i = 0,l,r,d; i < k; ++ i){
        cin >> l >> r >> d;
        ls.push_back(l);
        rs.push_back(r);
        ds.push_back(d);
    }

    sort(A.begin(), A.end(), greater<int>());
    auto chk = [&](int mid)->bool{
        int x = A[mid];
        for (int i = 0; i < k; ++ i){
            if (ds[i] > x){
                diff[ls[i]-1] += 1;
                diff[rs[i]] -= 1;
            }
        }
        int res = n+1, cur = 0;
        for (int i = 0; i <= n; ++ i){
            cur += diff[i];
            if (cur) res += 2;
            diff[i] = 0;
        }
        return res <= tar;
    };

    int lo = 0, hi = m-1;
    while (lo < hi){
        int mid = (lo+hi+1) >> 1;
        if (chk(mid)) lo = mid;
        else hi = mid-1;
    }

    if (chk(lo)) cout << lo+1 << "\n";
    else cout << 0 << "\n";
}
