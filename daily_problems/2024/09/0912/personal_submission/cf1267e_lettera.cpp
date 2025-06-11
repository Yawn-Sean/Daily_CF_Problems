#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 1?998244353:1e9+7;
const int N=1e5+5;
const int inf=1e9;
//#define int ll
void solve()
{
     int n,m;
     cin>>m>>n;
     //想法1:枚举要让哪个candidate elected，有可能不存在
     //2:二分要cancel的仓的数量
     //注意到n，m很小
     vector<vector<int>>a(n,vector<int>(m));
     vector<vector<int>>b(n,vector<int>(m+1));
     for(int i=0;i<n;i++)
     {
     	for(int j=0;j<m;j++)
     	{
     		cin>>a[i][j];
     		 b[i][j]=a[i][j];
     	}
     	b[i][m]=i;
     }
     int ans=n;//n个票仓，m个人
     int id=m;
     for(int i=0;i<m-1;i++)
     {
     	sort(a.begin(),a.end(),[&](vector<int>x,vector<int>y){
     		return x[i]-x[m-1]<y[i]-y[m-1];
     	});
     	int res=0,dif=0;
     	for(int j=0;j<n;j++)
     	{
     		dif+=a[j][i]-a[j][m-1];
     	}
     	int top=0;
     	while(dif<0)
     	{
     		dif-=a[top][i]-a[top][m-1];
     		top++;
     	}
     	if(ans>top)
     	{
     		id=i;
     	}
     	ans=min(ans,top);
     }
     cout<<ans<<endl;
     int i=id;
     sort(b.begin(),b.end(),[&](vector<int>x,vector<int>y){
     		return x[i]-x[m-1]<y[i]-y[m-1];
     	});
     	for(int j=0;j<ans;j++)
     	{
     		cout<<b[j][m]+1<<" ";
     	}
     	cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
