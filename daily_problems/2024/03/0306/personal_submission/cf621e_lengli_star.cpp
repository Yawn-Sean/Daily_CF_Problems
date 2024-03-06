//首先不难想到dp,但是数据范围很令人头疼,但是如果可以矩阵快速幂那就很好！
//定义dp(i,j)表示选了i个数字,模x余j的方案数
//那么枚举当前选择的数字k,则有转移dp(i+1,(j+k)%x)+=dp(i,j)
//既然使用矩阵快速幂,那么我们只需要考虑dp(j)即可
//tip:  '#'为手动转置QAQ
//那么我们要构造一个转移矩阵A，使其乘上[dp(0),dp(1)...dp(x-1)]#
//那么新的dp要根据不同数字贡献组成的行向量进行线性变换得到，那么利用递推式构造A即可
//初始化仅有一个列向量
//左乘A^b后，f[k][0]即为答案。


/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  bool operator<(const ModInt &a) const { return (x < a.x); }
  bool operator>(const ModInt &a) const { return (x > a.x); }
  bool operator<=(const ModInt &a) const { return (x <= a.x); }
  bool operator>=(const ModInt &a) const { return (x >= a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
  friend std::istream &operator>>(std::istream &is, ModInt &a) {int v;is >> v;a = ModInt(v);return is;}
};
constexpr unsigned MO = 1000000007;
using Mint = ModInt<MO>;

template<typename T> struct matrix {
	int n, m;
	std::vector<T> data;
	matrix () : matrix(0, 0) {}
	matrix (int n) : matrix(n, n) {}
	matrix (int n, int m) : n(n), m(m), data(n * m) {}
	matrix (const std::vector<std::vector<T> > &a) : n(a.size()), m(a[0].size()) {
		data.resize(n*m);
		for (int i = 0; i < n; i++) {
			copy(a[i].begin(), a[i].end(), data.begin()+i*m);
		}
	}
	auto operator [] (int i) { return data.begin() + i * m; }
	auto operator [] (int i) const { return data.cbegin() + i * m; }
	static matrix mul_ident(int n) {
		matrix res(n, n);
		for (int i = 0; i < n; i++) res[i][i] = 1;
		return res;
	}
	matrix operator + (const matrix &rhs) {
		assert(n == rhs.n && m == rhs.m);
		matrix res(n,m);
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < m; j++)
				res[i][j] = (*this)[i][j] + rhs[i][j];
		}
		return res;
	}
	matrix operator - (const matrix &rhs) {
		assert(n == rhs.n && m == rhs.m);
		matrix res(n,m);
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < m; j++)
				res[i][j] = (*this)[i][j] - rhs[i][j];
		}
		return res;
	}
	matrix operator * (const matrix &rhs) {
		assert(m == rhs.n);
		matrix res(n, rhs.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < rhs.m; k++)
			res[i][k] += (*this)[i][j] * rhs[j][k];
		return res;
	}
	template<typename int_t> matrix operator ^ (int_t x) {
		assert(n == m);
		matrix res = mul_ident(n);
		while (x) {
			if (x & 1) res = matrix(*this)*res;
			*this = matrix(*this)*matrix(*this);
			x>>=1;
		}
		return res;
	}
	matrix &operator += (const matrix &rhs) { return *this = *this + rhs;}
	matrix &operator -= (const matrix &rhs) { return *this = *this - rhs;}
	matrix &operator *= (const matrix &rhs) { return *this = *this * rhs;}
	template<typename int_t> matrix &operator ^= (int_t x) { return *this = *this ^ x;}
	bool operator == (const matrix &rhs) const { return m == rhs.m && data == rhs.data; }
	bool operator != (const matrix &rhs) const { return m != rhs.m || data != rhs.data; }
	std::pair<bool, matrix> inv() {
		assert(n == m);
		matrix a = *this;
		matrix r = mul_ident(n);
		for (int i = 0; i < n; i++) {
			int id = -1;
			for (int j = i; j < n; j++) if (a[j][i] != T(0)) { id = j; break; }
			if (id == -1) return {false, matrix()};
			for (int j = i; j < n; j++) std::swap(a[i][j], a[id][j]);
			for (int j = 0; j < n; j++) std::swap(r[i][j], r[id][j]);
			auto t = T(1) / a[i][i];
			for (int j = i; j < n; j++) a[i][j] *= t;
			for (int j = 0; j < n; j++) r[i][j] *= t;
			for (int j = 0; j < n; j++) if (i != j) {
				auto s = a[j][i];
				for (int k = i; k < n; k++) a[j][k] -= a[i][k] * s;
				for (int k = 0; k < n; k++) r[j][k] -= r[i][k] * s;
			}
		}
		return {true, r};
	}
	std::pair<bool, matrix> inv2() {
		assert(n == m);
		matrix a = *this;
		std::vector<std::pair<int, int> > swaps;
		for (int i = 0; i < n; i++) {
			int id = -1;
			for (int j = i; j < n; j++) if (a[j][i] != T(0)) { id = j; break; }
			if (id == -1) return {false, matrix()};
			if (id != i) {
				swaps.push_back({id, i});
				for (int j = 0; j < n; j++) std::swap(a[i][j], a[id][j]);
			}
			a[i][i] =  T(1) / a[i][i];
			for (int j = 0; j < n; j++) if (j != i) a[i][j] *= a[i][i];
			for (int j = 0; j < n; j++) if (j != i) {
				for (int k = 0; k < n; k++) if (k != i) a[j][k] -= a[j][i] * a[i][k];
				a[j][i] *= -a[i][i];
			}
		}
		for (int i = swaps.size(); i--; ) 
			for (int j = 0; j < n; j++) std::swap(a[j][swaps[i].first], a[j][swaps[i].second]);
		return {true, a};
	}
	T det() const {
		assert(n == m);
		matrix a = *this;
		T res = 1;
		for (int i = 0; i < n; i++) {
			int id = -1;
			for (int j = i; j < n; j++) if (a[j][i] != T(0)) { id = j; break; }
			if (id == -1) return 0;
			if (id != i) {
				res = -res;
				for (int j = i; j < n; j++) std::swap(a[id][j], a[i][j]);
			}
			res *= a[i][i];
			
			T t = T(1) / a[i][i];
			for (int j = i; j < n; j++) a[i][j] *= t;
			for (int j = i + 1; j < n; j++) {
				auto s = a[j][i];
				for (int k = i; k < n; k++) a[j][k] -= a[i][k] * s;
			}
		}
		return res;
	}
};

int n,b,k,x;

void solve(){
    cin>>n>>b>>k>>x;
    vector<int> cnt(10,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    matrix<Mint> a(100,100);
    for(int i=0;i<x;i++){
        for(int j=0;j<max(x,10);j++){
            for(int k=0;k<10;k++){
                if((j*10%x+k)%x==i) {
                    a[i][j]+=cnt[k];
                }
            }
        }
    }
    matrix<Mint> res(100,100);
    for(int i=0;i<=9;i++){
        if(cnt[i]) res[i][0]=cnt[i];
    }
    a=a^(b-1);
    res=a*res;
    cout<<res[k][0]<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
