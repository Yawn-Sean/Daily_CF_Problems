#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//模拟
//x是最后得到球的位置
void sol()
{
    int n,x;cin>>n>>x;
    vector<i64>a(n+1);
    i64 _min=1e9+7;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<_min)
        {
            _min=a[i];
        }
    }
    for(int i=1;i<=n;++i)a[i]-=_min;
    _min*=n;//进行n轮的情况下
    while(a[x])
    {
        a[x]--;_min++;
        x=(n+x-2)%n+1;
    }
    a[x]=_min;
    for(int i=1;i<=n;++i)cout<<a[i]<<' ';
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
