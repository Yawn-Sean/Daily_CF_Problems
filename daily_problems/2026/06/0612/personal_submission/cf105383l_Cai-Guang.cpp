#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

using i64 = long long;
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<i64 P>
struct MLong {
    i64 x;
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{norm(x % getMod())} {}
     
    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    explicit constexpr operator i64() const {
        return x;
    }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong &operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MLong &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
i64 MLong<0LL>::Mod = i64(1e12) + 9;
 
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
     
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 998244353;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 1000000007;
using Z = MInt<P>;

void solve() {
    int n, m, s, t, x, k;
    cin >> n >> m >> s >> t >> x >> k;

    vector<vector<i64>> G(n + 1, vector<i64>(n + 1, 1e12));
    vector<vector<Z>> val(n + 1, vector<Z>(n + 1));

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (G[i][j] > 1e9) {
                G[i][j] = 1e12;
                val[i][j] = 0;
            } else {
                val[i][j] = G[i][j];
            }
        }
    }

    auto norm = [&](vector<vector<i64>>& g) -> void {
        map<i64, i64> mp;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[g[i][j]] ++;
            }
        }

        int idx = 0;

        for (auto &[x, y] : mp) {
            if (x == -1 || x == 0 || x > 1e9) {
                y = 1e12;
                continue;
            }
            y = ++idx;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = mp[g[i][j]];
            }
        }
    };

    norm(G);

    vector<vector<vector<i64>>> nG(31, vector<vector<i64>>(n + 1, vector<i64>(n + 1, 1e12)));
    
    vector<vector<vector<Z>>> nVal(31, vector<vector<Z>>(n + 1, vector<Z>(n + 1)));
    
    nG[0] = G;
    nVal[0] = val;

    int base = n * n;
    for (int now = 1; now <= 30; now ++) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (nG[now][i][j] > nG[now - 1][i][k] * base + nG[now - 1][k][j]) {
                        nG[now][i][j] = nG[now - 1][i][k] * base + nG[now - 1][k][j];
                        nVal[now][i][j] = nVal[now - 1][i][k] * power(Z(x), 1 << (now - 1)) + nVal[now - 1][k][j];
                    }
                }
            }
        }
        norm(nG[now]);
    }

    bool have = false;
    vector<vector<i64>> use(n + 1, vector<i64>(n + 1, 1e12));
    vector<vector<Z>> ans(n + 1, vector<Z>(n + 1));

    for (int now = 30; now >= 0; now--) {
        if (k >> now & 1) {
            if (!have) {
                ans = nVal[now];
                use = nG[now];
                have = true;
                continue;
            }

            
            vector<vector<i64>> nUse(n + 1, vector<i64>(n + 1, 1e12));
            vector<vector<Z>> nAns(n + 1, vector<Z>(n + 1));

            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (nUse[i][j] > use[i][k] * base + nG[now][k][j]) {
                            nUse[i][j] = use[i][k] * base + nG[now][k][j];
                            nAns[i][j] = ans[i][k] * power(Z(x), 1 << now) + nVal[now][k][j];
                        }
                    }
                }
            }

            use = nUse;
            ans = nAns;
            norm(use);
        }
    }

    if (use[s][t] > 1e9) {
        cout << -1 << '\n';
        return;
    }
    cout << ans[s][t] << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	
	// cin >> t;
	
	while (t --) {
		solve();
	}
} 
