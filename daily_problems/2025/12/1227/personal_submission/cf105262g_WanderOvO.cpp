#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const LL P = 1e9 + 7;
const int MOD1 = 1e9 + 9;
const int MOD2 = 998244353;
const int N = 1e6 + 10;

/*
s[i] = a[1] + ... + a[i]
s2[i] = i * a[1] + (i - 1) * a[2] + ... + a[i]
s2[j] = j * a[1] + (j - 1) * a[2] + ... + a[j]
(i - j) * a[j + 1] + (i - j - 1) * a[j + 2] + ... + a[i]
s2[i] - s2[j] - s[j] * (i - j)
*/

struct MyHash {
    LL MOD, n, p[N], h[N], rh[N], P;

    void init(vector<LL> &s, LL power, LL mod) {
        n = s.size();
        MOD = mod;
        P = power;
        p[0] = 1;
        h[0] = s[0];
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * P + s[i];
            h[i] %= MOD;
        }
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P % MOD;
        }
        rh[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rh[i] = rh[i + 1] * P + s[i];
            rh[i] %= MOD;
        }
    }
    
    void reset(int nn) {
        for (int i = 0; i < nn; i++) {
            p[i] = 0;
        }
        for (int i = 0; i < nn; i++) {
            h[i] = 0;
        }
        for (int i = 0; i < nn; i++) {
            rh[i] = 0;
        }
    }
    
    LL get(int l, int r) {
        if (l == 0) return h[r];
        return (((h[r] - h[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD);
    }

    LL rget(int l, int r) {
        if (r == n - 1) return rh[l];
        return (((rh[l] - rh[r + 1] * p[r - l + 1]) % MOD + MOD) % MOD);
    }
};

MyHash h1, h2;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    vector<LL> s(n + 1, 0), s2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
        s[i + 1] %= P;
    }    
    for (int i = 1; i <= n; i++) {
        s2[i] = s2[i - 1] + s[i];
        s2[i] %= P;
    }
    
    h1.init(a, P, MOD1);
    h2.init(a, P, MOD2);
    
    auto check = [&] (int l, int r) -> bool {
        return (h1.get(l, r) == h1.rget(l, r)) && (h2.get(l, r) == h2.rget(l, r)); 
    };
    
    auto solve_odd = [&] (int center) -> LL {
        int l = 1, r = min(center + 1, n - center), mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(center - mid + 1, center + mid - 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        LL len = -1;
        if (check(center - r + 1, center + r - 1)) {
            len = r;
        } else {
            len = l;
        }
        
        
        int i = center + len;
        int j = center;
        LL res = s2[i] - s2[j] - s[j] * (i - j);
        res *= 2;
        res -= a[center] * len;
        return res;
    };
    
    auto solve_even = [&] (int center) -> LL {
        int l = 0, r = min(center + 1, n - center - 1), mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(center - mid + 1, center + mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        LL len = -1;
        if (check(center - r + 1, center + r)) {
            len = r;
        } else {
            len = l;
        }
        // cout << len << "\n";
        
        if (len == 0) {
            return 0;
        }
        
        int i = center + 1 + len;
        int j = center + 1;
        LL res = s2[i] - s2[j] - s[j] * (i - j);
        return 2 * res;
    };
    
    
    LL res = 0;
    for (int i = 0; i < n; i++) {
        res += solve_odd(i);
        res %= P;
        // cout << "out_res:" << res << "\n";
        res += solve_even(i);
        res %= P;
        // cout << "out_res:" << res << "\n";
    }
    cout << (res % P + P) % P << "\n";
}

int main() {
    #ifdef LOCAL_TEST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
