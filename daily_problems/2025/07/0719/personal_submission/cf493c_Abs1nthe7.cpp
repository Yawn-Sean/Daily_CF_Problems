#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
void sol()
{
    int n;cin>>n;
    vector<i64>a(n);
    for(auto &x:a)cin>>x;
    int m;cin>>m;
    vector<i64>b(m);
    for(auto &x:b)cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    i64 now=1e18;
    int p1=0,p2=0,ans1=3*n,ans2=3*m;
    while(p1<n||p2<m)
    {
        now=1e18;
        if(p1<n)now=min(now,a[p1]);
        if(p2<m)now=min(now,b[p2]);
        if(p1<n&&now==a[p1])p1++;
        if(p2<m&&now==b[p2])p2++;
        int tmp1=2*p1+3*(n-p1);
        int tmp2=2*p2+3*(m-p2);
        if(tmp1-tmp2>ans1-ans2)
        {
            ans1=tmp1;
            ans2=tmp2;
        }
    }
    cout<<ans1<<':'<<ans2<<endl;
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
