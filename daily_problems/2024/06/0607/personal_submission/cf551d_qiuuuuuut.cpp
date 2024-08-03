#include <bits/stdc++.h>
using namespace std;
const int N=2;
#define int long long 
#define endl '\n'
int n,mod,m,k,l;
struct Matrix {
  int a[3][3];

  Matrix() { memset(a, 0, sizeof a); }

  Matrix operator*(const Matrix &b) const {
    Matrix res;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= 2; ++j)
        for (int k = 1; k <= 2; ++k)
          res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
    return res;
  }
} ans, base;


int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

void mqpow(int b) {
  while (b) {
    if (b & 1) ans = ans * base;
    base = base * base;
    b >>= 1;
  }
}


void solve()
{
	cin>>n>>k>>l>>mod;
	if(mod==1) 
	{
		cout<<0;return;
	}
	if(l<=60&&k>=(1LL<<l)) 
	{
		cout<<0;return;
	}
	base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    ans.a[1][1] = ans.a[1][2] = 1;
    mqpow(n-1);
	int c0=ans.a[1][1] + ans.a[1][2];
	int c1=((qpow(2,n)-c0)%mod+mod)%mod;
	int s=1;
	for(int i=0;i<l;i++)
	{
		if(k>>i&1) s=s*c1%mod;
		else s=s*c0%mod; 
	}
	cout<<s;
}
signed main()
{
	int T=1;
	while(T--) solve();
	return 0;
 } 
