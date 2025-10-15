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
    int n,m,k;
    std::cin>>n>>m>>k;
    int flag=1;
    int l=n+1,r=0,num=0;
    while(m--){
        int u,v;
        std::cin>>u>>v;
        if(v!=u+1 and v!=u+k+1) flag=0;
        else if(v==u+k+1){
            l=std::min(l,u);
            r=std::max(r,u);
            num++;
        }
    }
    if(r and r-l>k) flag=0;
    Mint res=0;
    if(!flag) res=0;
    else{
        if(r){
            for(int i=std::max(r-k,1);i<=l;i++){
                int t=std::min(i+k,n-k-1)-i-num;
                if(i==l) t++;
                if(t>=0) res+=Mint(2).pow(t);
            }
        }else{
            res+=1;
            for(int i=1;i<=n-k-1;i++){
                int t=std::min(n-k-1,i+k)-i;
                if(t>=0) res+=Mint(2).pow(t);
            }
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
