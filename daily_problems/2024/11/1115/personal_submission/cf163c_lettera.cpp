#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 ll n,l,v1,v2;
	 cin>>n>>l>>v1>>v2;
	 //首先枚举每个点，在差分数组能吃掉它的位置上加1
	 //然后前缀和差分数组
	 //最后得到每个点能吃多少个巧克力
	 //最后除以2l,同个数巧克力相加就是ans
	 vector<ll>a(n+1);
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	a[i]*=(v1+v2);
	 }
	 l*=(v1+v2);
	 ll len=l/(v1+v2)*v2;
	 map<ll,int>d;
	 for(int i=1;i<=n;i++)
	 {
	 	ll x=(a[i]-len);
	 	if(x<0)
	 	{
	 		x+=2*l;
	 		d[0]++;
	 		d[a[i]]--;
	 		d[x]++;
	 		d[2*l]--;
	 	}
	 	else
	 	{
	 		d[x]++;
	 		d[a[i]]--;
	 	}
	 }
	 vector<ll>ans(n+1);
	 d[2*l]+=0;//!!!
	 ll last=-1;
	 for(auto &[x,y]:d)
	 {
	 	y+=d[last];
	 	ans[d[last]]+=x-max(last,0ll);
	 	last=x;
	 }
	 cout<<fixed<<setprecision(15);
	 for(auto x:ans)
	 {
	 	cout<<1.0*x/(2*l)<<"\n";
	 }
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
