#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
template <unsigned P> struct modint {
    unsigned v; modint() : v(0) {}
    template <class T> modint(T x) { x %= (int)P, v = x < 0 ? x + P : x; }
    modint operator+() const { return *this; }
    modint operator-() const { return modint(0) - *this; }
    modint inv() const { return assert(v), qpow(*this, P - 2); }
    friend int raw(const modint &self) { return self.v; }
    template <class T> friend modint qpow(modint a, T b) {
        modint r = 1;
        for (; b; b >>= 1, a *= a) if (b & 1) r *= a;
        return r;
    }
    modint &operator+=(const modint &rhs) { if (v += rhs.v, v >= P) v -= P; return *this; }
    modint &operator-=(const modint &rhs) { if (v -= rhs.v, v >= P) v += P; return *this; }
    modint &operator*=(const modint &rhs) { v = 1ull * v * rhs.v % P; return *this; }
    modint &operator/=(const modint &rhs) { return *this *= rhs.inv(); }
    friend modint operator+(modint lhs, const modint &rhs) { return lhs += rhs; }
    friend modint operator-(modint lhs, const modint &rhs) { return lhs -= rhs; }
    friend modint operator*(modint lhs, const modint &rhs) { return lhs *= rhs; }
    friend modint operator/(modint lhs, const modint &rhs) { return lhs /= rhs; }
    friend bool operator==(const modint &lhs, const modint &rhs) { return lhs.v == rhs.v; }
    friend bool operator!=(const modint &lhs, const modint &rhs) { return lhs.v != rhs.v; }
};
 
typedef modint<1000000007> mint;
template <int N>
struct C_prime {
  mint fac[N + 10], ifac[N + 10];
  C_prime() {
    for (int i = raw(fac[0] = 1); i <= N; i++) fac[i] = fac[i - 1] * i;
    ifac[N] = 1 / fac[N];
    for (int i = N; i >= 1; i--) ifac[i - 1] = ifac[i] * i;
  }
  mint operator()(int n, int m) {
    return n >= m ? fac[n] * ifac[m] * ifac[n - m] : 0;
  }
};
 
C_prime<400005> C;
 
void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<ll, int> cnt, st, ed;
    vector<ll> dis;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        dis.push_back(u);
        dis.push_back(v);
        st[u]++;
        ed[v]++;
    }
    sort(all(dis));
    dis.erase(unique(all(dis)), dis.end());
    ll prev = -1000000007, val = 0;
    mint ans = 0;
    for (ll p : dis) {
        mint gap = p - prev - 1;
        if (val >= k) {
            ans += (gap * C(val, k));
        }
        for (int i = 0; i < st[p]; i++) {
            val++;
        }
        cnt[p] = val;
        for (int i = 0; i < ed[p]; i++) {
            val--;
        }
        prev = p;
    }
    for (auto [x, num] : cnt) {
        if (num >= k) {
            ans += C(num, k);
        }
    }
    cout << ans.v << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
