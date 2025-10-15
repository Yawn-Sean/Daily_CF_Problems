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

#define int long long

struct combine{
    std::vector<int> aa,bb,inv;
    int mx,MOD;
    combine(){}
    combine(int len,int M){
        mx=len,MOD=M;
        aa.clear(),bb.clear(),inv.clear();
        aa.resize(len),bb.resize(len),inv.resize(len);
        inv[1]=1;
        for(int i=2;i<len;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
        aa[0]=1,bb[0]=1;
        for(int i=1;i<len;i++) aa[i]=(i*aa[i-1])%MOD;
        for(int i=1;i<len;i++) bb[i]=(inv[i]*bb[i-1])%MOD;
    }
    int C(int x, int y) {
        assert(x<mx and y<mx);
        return x<y or y<0 ? 0: aa[x]*bb[y]%MOD*bb[x-y]%MOD;
    }
};

void solve(){
    i64 n,m,k;
    std::cin>>n>>m>>k;
    combine tr(n+2,1000000007);
    std::vector<Mint> f(k+2);

    i64 v=m/n;
    std::vector<i64> cnt(n+2,v);
    for(int i=0;i<m%n;i++) cnt[i]++;

    f[0]=1;

    std::vector<std::vector<Mint>> y(n+2,std::vector<Mint> (n+2));
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            y[i][j]=Mint(tr.C(n,j)).pow(cnt[i]);
        }
    }
 
    for(int i=0;i<n;i++){
        std::vector<Mint> g(k+2);
        for(int j=0;j<=k;j++){
            for(int l=0;l<=std::min(n,1ll*j);l++){
                g[j]+=f[j-l]*y[i][l];
            }
        }
        f.swap(g);
    }

    std::cout<<f[k]<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
