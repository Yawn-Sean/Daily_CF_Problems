#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//对于n顶点组成的多边形，显然连成的对角线是n/2,三角形是n-2;
//所以考虑取点的时候取个最大的多边形，我们考虑隔一个取一个，这样多的那块也是三角形
//所以我们应该先取奇数点
void sol()
{
    int n,x,y;cin>>n>>x>>y;
    vector<int>a(x);
    for(auto &c:a)cin>>c;
    sort(a.begin(),a.end());
    vector<int>ans;

    int cnt=x,now;
    for(int i=1;i<x;++i)
    {
        now=a[i]-a[i-1]-1;
        if(now&1)ans.push_back(now);
    }
    now=a[0]+n-a[x-1]-1;
    if(now&1)ans.push_back(now);
    sort(ans.begin(),ans.end());
    for(auto v:ans)
    {
       if(y>=v/2)
       {
         y-=v/2;
         cnt+=v;//加上这么多顶点
       }
    }
    cnt+=y*2;//有多的就随便放，贡献都是2
    cout<<min(n,cnt)-2<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)sol();
    return 0;
}
