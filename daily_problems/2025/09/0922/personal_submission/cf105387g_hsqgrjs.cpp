#include <bits/stdc++.h>

using i64 = long long;

#define dbg(x) std::cerr << #x << " = " << x << "\n"
#define println(...) std::cerr << #__VA_ARGS__ << std::endl
template <class T> void cmax( T& x , T y) { if(x < y) x = y;}
template <class T> void cmin( T& x , T y) { if(x > y) x = y;}

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    bool operator == (const ModInt &a) const { return x == a.x; };
    bool operator != (const ModInt &a) const { return x != a.x; };
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
    friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x;}
    friend std::istream &operator>>(std::istream &is, ModInt &t){return is >> t.x;}
 
    ModInt pow(int64_t n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
     
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
     
};
using Z = ModInt<1000000007>;

template<class T = int>
class Fenwicktree {
	std::vector<T> t;
public :
	Fenwicktree(int n): t(n + 1, 0) {}

	inline int lowbit(int x) { return x & -x; }

	void add(int x, T y) {
		while (x < t.size()) {
			t[x] += y;
			x += lowbit(x);
		}
	}

	T quiry(int x) {
		T ans = 0;
		while (x) ans += t[x], x -= lowbit(x);
		return ans;
	}

	T quiry(int l, int r) {
		assert(l > 0);
		return quiry(r) - quiry(l - 1);
	}
};


void solve() {
	int n, K[3];
	std::cin >> n >> K[0] >> K[1] >> K[2];
	
	std::vector<Fenwicktree<Z>> dp(3, Fenwicktree<Z>(n));
	for (int i = 0; i < 3; i++) {
		dp[i].add(1, 1);
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j != k) {
					dp[j].add(i, dp[k].quiry(std::max(i - K[j], 1), i - 1));
				}
			}
			if (i - K[j] < 1) {
				dp[j].add(i, 1);
			}
		}
	}

	Z ans = 0;
	for (int i = 0; i < 3; i++) ans += dp[i].quiry(n, n);
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
