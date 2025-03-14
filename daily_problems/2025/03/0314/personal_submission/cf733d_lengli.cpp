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
    int n;
    std::cin>>n;

    std::vector<std::vector<char>> g(n+2,std::vector<char> (3)); 

    int ex=-1,ey=-1;

    for(int j=0;j<3;j++){
        for(int i=1;i<=n;i++){
            std::cin>>g[i][j];
            if(g[i][j]=='O') ex=i,ey=j;        
        }
    }

    std::vector<std::vector<int>> dir={
        {0,1},{1,0},{0,-1},{-1,0}
    };

    auto modify=[&](int r,char c)->bool{
        for(int i=1,x=ey,y=ex;i<3;i++){
            x +=dir[r][0],y+=dir[r][1];
            if(x<0 or x>2) return 0;
            if(y<1 or y>n) return 0;
            if(g[y][x]==c) return 0;
        }
        for(int i=1,x=ey,y=ex;i<3;i++){
            x+=dir[r][0],y+=dir[r][1];
            g[y][x]=c;
        }
        return 1;
    };

    auto check=[&](){
        std::vector<std::vector<Mint>> f(n+2,std::vector<Mint> (8));
        f[0][7]=1;
        for(int i=1;i<=n;i++){
            for(int mask=0;mask<8;mask++){
                f[i][mask]=f[i-1][7-mask];
            }
            for(int t=3;t<8;t*=2){
                for(int mask=0;mask<8;mask++){
                    if((mask&t)==t) f[i][mask]+=f[i][mask^t];
                }
            }
            int v=0;
            for(int j=0;j<3;j++){
                if(g[i][j]!='.') v^=(1<<j);
            }
            for(int mask=7;mask>=0;mask--){
                if((mask&v)==0) f[i][mask|v]=f[i][mask];
                if((mask&v)!=v) f[i][mask]=0;
            }
        }

        return f[n][7];
    };

    Mint res=0;

    for(int mask=1;mask<(1<<4);mask++){
        int f=-1;
        for(int i=0;i<4;i++){
            if(mask>>i&1){
                if(!modify(i,'X')){
                    for(int j=0;j<i;j++) modify(j,'.');
                    f=0;
                    break;
                }
                f*=-1;
            }
        }
        if(!f) continue;
        res+=check()*f;
        for(int i=0;i<4;i++)
            if(mask>>i&1) modify(i,'.');
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
