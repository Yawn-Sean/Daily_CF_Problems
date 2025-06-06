/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

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
        matrix a = *this;
        while (x) {
            if (x & 1) res = a * res;
            a = a * a;
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


void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> s(n),l(n);
    for(int i=0;i<n;i++) std::cin>>s[i];
    for(int i=0;i<n;i++) std::cin>>l[i];

    matrix<Mint> a(n,2),b(2,n);
    for(int i=0;i<n;i++){
        a[i][0]=(Mint)s[i]+l[i];
        a[i][1]=(Mint)l[i]*-1;
    }
    for(int i=0;i<n;i++){
        b[0][i]=(Mint)s[i]+l[i];
        b[1][i]=(Mint)l[i];
    }

    matrix<Mint> f(n,1);
    f[0][0]=1;

    matrix<Mint> tmp=b*a;
    
    tmp^=(m-1);
    auto res=(a*tmp)*(b*f);

    Mint ans=0;
    for(int i=0;i<n;i++) ans+=res[i][0];
    std::cout<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
