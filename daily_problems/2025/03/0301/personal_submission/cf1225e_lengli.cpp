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

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n+2,std::vector<char>(m+2));
    std::vector<std::vector<i64>> rs(n+2,std::vector<i64> (m+2,0));
    std::vector<std::vector<i64>> ds(n+2,std::vector<i64> (m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            std::cin>>g[i][j];
            if(g[i][j]=='R'){
                rs[i][j]=1;
                ds[i][j]=1;
            }
        }
    }
    if(n==1 and m==1){
        std::cout<<(rs[1][1]^1)<<"\n";
        return;
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            ds[i][j]+=ds[i][j+1];
            rs[i][j]+=rs[i+1][j];
        }
    }
    std::vector<std::vector<Mint>> r(n+2,std::vector<Mint> (m+2,0));
    std::vector<std::vector<Mint>> d(n+2,std::vector<Mint> (m+2,0));
    std::vector<std::vector<Mint>> sd(n+2,std::vector<Mint> (m+2,0));
    std::vector<std::vector<Mint>> sr(n+2,std::vector<Mint> (m+2,0));
    r[n][m]=d[n][m]=sd[n][m]=sr[n][m]=1;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(i==n and j==m) continue;
            r[i][j] = sd[i][j+1]-sd[i][m-ds[i][j+1]+1];
            d[i][j] = sr[i+1][j]-sr[n-rs[i+1][j]+1][j];
            sr[i][j] = sr[i+1][j]+r[i][j];
            sd[i][j] = sd[i][j+1]+d[i][j];
        }
    }
    std::cout<<r[1][1]+d[1][1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
