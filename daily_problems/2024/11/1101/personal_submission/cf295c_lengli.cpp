/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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

constexpr int N=55,M=1000000007;

Mint aa[N],bb[N];
Mint inv[N];
 
void init(){
    inv[1] = 1;
    for(int i = 2;i < N;i++)  inv[i] = (M -  M / i) * inv[M % i];
    aa[0]=1,bb[0]=1;
    for(int i=1;i<N;i++) aa[i]=(i*aa[i-1]);
    for(int i=1;i<N;i++) bb[i]=(inv[i]*bb[i-1]);
}
 
Mint C(int x, int y) {
    return x < y || y < 0 ? 0 : aa[x] * bb[y]  * bb[x - y] ;
}

void solve(){
    int n,k;
    std::cin>>n>>k;
    int c50=0,c100=0;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        if(x==50) c50++;
        else c100++;
    }
    std::vector<std::vector<std::vector<Mint>>> f(2,std::vector<std::vector<Mint>> (c50+2,std::vector<Mint> (c100+2,0)));

    f[0][c50][c100]=1;

    for(int t=1;t<=4*n;t++){
        auto &g=f[t%2];
        auto &la=f[(t%2)^1];
        for(int i=0;i<=c50;i++){
            for(int j=0;j<=c100;j++){
                int di=c50-i,dj=c100-j;
                for(int ii=di;ii<=c50;ii++){
                    for(int jj=dj;jj<=c100;jj++){
                        int v=(ii-di)*50+(jj-dj)*100;
                        if(v>k or (di==ii and dj==jj)) continue;
                        g[i][j]+=la[ii][jj]*C(ii,ii-di)*C(jj,jj-dj);
                    }
                }
            }
        }
        if(t&1){
            if(g[c50][c100]){
                std::cout<<t<<"\n";
                std::cout<<g[c50][c100]<<"\n";
                return;
            }
        }
    }
    std::cout<<"-1"<<"\n";
    std::cout<<"0"<<"\n";
    
}

signed main(){
    fastio;
    init();
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
