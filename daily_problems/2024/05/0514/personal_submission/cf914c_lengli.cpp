// Problem: C. Travelling Salesman and Special Numbers
// Contest: Codeforces - Codecraft-18 and Codeforces Round 458 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/914/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
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

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=1010;

string s;
int k;
Mint f[N][N][2];
bool st[N][N][2];
int g[N];
int a[N],pos;

Mint dfs(int pos,int cnt,bool limit,bool zero){
	if(!pos) return !zero and g[cnt]+1==k;
	auto &res=f[pos][cnt][zero];
	if(!limit and st[pos][cnt][zero]) return res;
	Mint ans=0;
	int ma=(limit ? a[pos] : 1);
	for(int i=0;i<=ma;i++){
		ans+=dfs(pos-1,cnt+(i==1),limit and i==ma,zero and i==0);
	}
	if(!limit) res=ans,st[pos][cnt][zero]=1;
	return ans; 
}

Mint cal(){
	pos=0;
	reverse(all(s));
	for(int i=0;i<s.size();i++) a[++pos]=s[i]-'0';
	return dfs(pos,0,1,1);
}

void solve(){
	cin>>s;
	cin>>k;
	if(k==0){
		cout<<1<<endl;
		return;
	}
	g[1]=0;
	for(int i=2;i<N;i++){
		int cnt=0;
		for(int j=0;j<11;j++){
			if(i>>j&1) cnt++;
		}
		g[i]=g[cnt]+1;
	}
	auto res=cal();
	if(k==1) res-=1;
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
