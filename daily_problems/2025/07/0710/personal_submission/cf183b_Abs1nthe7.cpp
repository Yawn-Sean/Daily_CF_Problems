#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//题意；从m个点出发最多能看到几个鸟
//如何把他们最大程度的划分到一条线上？
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first)return a.second<b.second;
    else return a.first<b.first;
}
void sol()
{
   int n,m;cin>>n>>m;
   vector<pair<int,int>>a(m);
   for(int i=0;i<m;++i)cin>>a[i].first>>a[i].second;
   map<tuple<int,int,i64>,int>mp;
   sort(a.begin(),a.end(),cmp);
   for(int i=0;i<m;++i)
   {
     auto [x1,y1]=a[i];
     for(int j=0;j<i;++j)
     {
        auto [x2,y2]=a[j];
        int dx=x2-x1,dy=y2-y1;
        int gcd=__gcd(dx,dy);
        dx/=gcd,dy/=gcd;
        // 斜率 (dx, dy)，截距 (dx * y - dy * x)
        if (dx < 0 || (dx == 0 && dy < 0))
        dx = -dx, dy = -dy;
        mp[{dx,dy,1ll*x1*dy-1ll*y1*dx}]++;
     }
   }
   vector<int>ans(n+1,0);

   for(auto &[k,v]:mp)
   {
     auto [dx,dy,c]=k;
     //i * dy == c ⇒ i == c / dy （必须是整数）
     if(dy&&c%dy==0&&c/dy>=1&&c/dy<=n)
     {
        ans[c/dy]=max(ans[c/dy],v);
     }
   }

   int res=0;
   //原来mp记录的是对数，现在要反推回去
   //ans[i]=k*(k-1)/2;
   for(int i=1;i<=n;++i)
   {
    res+=sqrt(ans[i]*2)+1;
   }
   cout<<res<<endl;
    return;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
