#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
int M=128;
vector<double>mul(vector<double>&a,vector<double>&b)
{
	vector<double>ret(M);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			ret[i^j]+=a[i]*b[j];
		}
	}
	return ret;
}
vector<double>qpow(vector<double>&a,int b)
{
	if (b == 1) return a;
    vector<double> ans = qpow(a, b / 2);
    ans = mul(ans, ans);
    if (b & 1) ans = mul(ans, a);
    return ans;
}
void solve()
{
	 int n,k;
	 cin>>n>>k;
	 vector<double>p(M);
	 for(int i=0;i<=k;i++){
	 	cin>>p[i];
	 }
	 cout<<fixed<<setprecision(20)<<(1-qpow(p,n)[0]);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
