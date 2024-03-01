//思路请参考小羊的题解QAQ，这里记录一下本人在阅读题解时候产生的思考
//Q:为什么采用对因子分段讨论a的计数，而不对a中的元素讨论可选因子进行技术？
//A:如果既要枚举最大值，又要遍历所有的a，那复杂度就炸了。

//Q:最后一段处理的公式如何理解？(k^s-(k-1)^s)
//A:相当与所有的情况减去每个位置最大取到(k-1)的所有情况。

//Q:为什么一定要有一个取最大值呢？
//A:因为枚举的就是最大值，如果不存在一个最大值，那么lcm可能会不等于当前枚举的值。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

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


const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ma=0;
    for(auto &x:a){
        cin>>x;
        ma=max(ma,x);
    }
    sort(all(a));
    Mint res=0;

    auto get=[&](int x){
        int l=0,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(a[mid]>=x) r=mid;
            else l=mid+1;
        }
        return r;
    };

    for(int x=1;x<=ma;x++){
        vector<int> fac;
        for(int j=1;j<=x/j;j++){
            if(x%j==0) {
                fac.push_back(j);
                if(x/j!=j) fac.push_back(x/j);
            }
        }
        sort(all(fac));
        Mint ans=1;
        int la=0;
        for(int i=1,j=0;i<fac.size();i++,la=j){
            j=get(fac[i]);
            Mint len=j-la;
            ans*=((Mint)i).pow(len.x);
        }
        Mint cnt=fac.size(),p=n-la;
        ans*=cnt.pow(p.x)-(cnt-1).pow(p.x);
        res+=ans;
    }
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
