//观察一会儿题目后感觉可以数位dp，答案为cal(b)-cal(a)-1。这里cal算小于x的排列。
//f[i][0/1]表示填完前i位后，达到上限/未达到上限的且小于x数量。
//如果没有到上限，那么后面可以随便填，使用不全相异元素的排列公式即可。
//如果达到上限则只能继续往后填，全部填完的情况要判断是否上限，上限说明相等，则不贡献数量。

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

const int N=1000010,M=1000000007;

Mint aa[N],bb[N];
Mint inv[N];
 
void init(){
    inv[1] = 1;
    for(int i = 2;i < N;i++)  inv[i] = (M -  M / i) * inv[M % i];
    aa[0]=1,bb[0]=1;
    for(int i=1;i<N;i++) aa[i]=(i*aa[i-1]);
    for(int i=1;i<N;i++) bb[i]=(inv[i]*bb[i-1]);
}

int cnt[30];
Mint f[N][2];
int a[N];
int idx;

Mint dfs(int pos,int limit){
    if(!pos) return !limit;
    auto &ans=f[pos][limit];
    if(limit and ans!=-1) return ans;
    if(!limit){
        Mint res=aa[pos];
        for(int i=0;i<26;i++){
            if(cnt[i]) res*=bb[cnt[i]];
        }
        return ans=res;
    }
    Mint res=0;
    for(int i=0;i<=a[pos];i++){
        if(cnt[i]){
            cnt[i]--;
            res+=dfs(pos-1,limit and i==a[pos]);
            cnt[i]++;
        }
    }
    return ans=res;
}

Mint cal(string s){
    idx=0;
    for(int i=0;i<1000010;i++) 
        for(int j=0;j<2;j++) f[i][j]=-1;
    reverse(all(s));
    for(int i=0;i<s.size();i++) a[++idx]=s[i]-'a';
    return dfs(idx,1);
}

void solve(){
    string a,b;
    cin>>a>>b;
    init();
    for(auto x:a) cnt[x-'a']++;
    cout<<cal(b)-cal(a)-1<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
