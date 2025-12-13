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
constexpr unsigned MO = 998244353;
using Mint = ModInt<MO>;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> b(n,std::vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>b[i][j];
        }
    } 

    if(n>m){
        std::vector<std::vector<int>> nb(m,std::vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nb[j][i]=b[i][j];
            }
        }
        std::swap(n,m);
        std::swap(b,nb);
    }

    Mint sum=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) sum*=(b[i][j]+1);
    }

    Mint inv2=Mint(2).inv(),inv12=Mint(12).inv();
    std::vector<std::vector<Mint>> f(n,std::vector<Mint> (m,0));
    std::vector<std::vector<Mint>> g(n,std::vector<Mint> (m,0));
    std::vector<Mint> rs(n,0),cs(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Mint v=b[i][j];
            f[i][j]=v*inv2;
            g[i][j]=v*(v+2)*inv12;
            rs[i]+=f[i][j];
            cs[j]+=f[i][j];
        }
    }

    std::vector<Mint> dp(1<<n,0);
    dp[0]=1;
    for(int j=0;j<m;j++){
        std::vector<Mint> ndp(1<<n,0);
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]) ndp[mask]=dp[mask]*cs[j];
        }

        for(int i=0;i<n;i++){
            for(int mask=0;mask<(1<<n);mask++){
                if(mask>>i&1) continue;
                if(dp[mask]){
                    ndp[mask|(1<<i)]+=dp[mask]*g[i][j];
                }
            }
        }
        dp.swap(ndp);
    }

    Mint res=0;
    for(int mask=0;mask<(1<<n);mask++){
        if(!dp[mask]) continue;
        Mint v=dp[mask];
        for(int i=0;i<n;i++){
            if(mask>>i&1) continue;
            v*=rs[i];
        }
        res+=v;
    }
    std::cout<<res*sum<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
