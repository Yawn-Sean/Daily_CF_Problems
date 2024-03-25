#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int P = 1000000009;
using i64 = long long;
// assume -P <= x < 2P
int modNorm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(modNorm(x)) {}
    Z(i64 x) : x(modNorm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(modNorm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = modNorm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = modNorm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

void solve() {
	int n, a, b, k; cin >> n >> a >> b >> k;
	string s; cin >> s;

	Z res = 0;
	for (int i = 0; i < k; i++){
		Z cur = power(Z(a), n - i) * power(Z(b), i);
		if (s[i] == '+') res += cur;
		else res -= cur;
	}


	//geometric series
	int blocks = (n + 1) / k;
	Z multi = power((Z(b) / Z(a)), k);
	//special case when coeff = 1
	if (multi.val() == 1){
		res *= blocks;
	}
	else {
		res *= (power(multi, blocks) - 1) / (multi - 1); 
	}
	cout << res.val() << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}