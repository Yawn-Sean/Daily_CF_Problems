#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 998244353;

// C a 取 b = fact[a] * infact[b - a] * infact[b]，注意取余
struct Comb {
    vector<int> fact, infact;

    int ksm(int a, int b, int mod) {
        a %= mod;
        int ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    
    Comb() {}
    Comb(int n) {
        fact.resize(n + 1);
        infact.resize(n + 1);
        fact[0] = infact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            infact[i] = infact[i - 1] * ksm(i, mod - 2, mod) % mod;
        }
    }

    int C(int a, int b, int mod) { // C a 取 b，对 mod 取余
        if (a < b) {
            return 0;
        }
        return fact[a] * infact[a - b] % mod * infact[b] % mod;
    }
};

// x 的阶乘
int factorial(int x, int mod) {
    if (x < 2) {
        return 1;
    }
    return x * factorial(x - 1, mod) % mod;
}

void solve() {
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    Comb comb(5000);

    function<int(int, int, int)> f = [&](int x, int y, int mod) -> int {
        int ans = 0;
        for (int i = 0; i <= min(x, y); ++i) {
            ans = (ans + (comb.C(x, i, mod)) % mod * comb.C(y, i, mod) % mod * factorial(i, mod) % mod) % mod;
        }
        return ans;
    };
    
    cout << f(a, b, mod) * f(a, c, mod) % mod * f(b, c, mod) % mod;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
