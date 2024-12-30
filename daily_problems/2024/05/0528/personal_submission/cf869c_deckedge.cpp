#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define aint64_t(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
const int mod = 998244353, N = 5e3 + 10;  
ve<int64_t> C(N);

inline int red() {
    int x;
    cin >> x;
    return x;
}

int64_t qmi(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b) { 
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int64_t cul(int a,int b) {
    int64_t res = 0;
    rep(i, 0, min(a, b) + 1) {
        int64_t pa = C[i] * C[a - i] % mod, pb;
        pa = C[a] * qmi(pa, mod - 2) % mod;
        pb = C[b] * qmi(C[b - i], mod - 2) % mod;
        res = (res + pa * pb % mod) % mod;
    }
    return res;
}

  
void solve() { 
    int a = red(), b = red(), c = red();  
    
    C[0] = 1;
    rep(i, 1, N) {
        C[i] = (int64_t)C[i - 1] * i % mod;
    }

    int64_t res = cul(a, b) % mod;
    res = res * cul(a, c) % mod;
    res = res * cul(b, c) % mod;
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

/*

https://codeforces.com/problemset/problem/869/C
*/


  

  

  

  

  
