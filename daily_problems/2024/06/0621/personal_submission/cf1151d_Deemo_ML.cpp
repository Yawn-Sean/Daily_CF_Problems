#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;

bool cmp(PII x,PII y)
{
    auto [a1,b1]=x;
    auto [a2,b2]=y;
    return a2+b1<a1+b2;
}

int main()
{
    LL n;
    cin>>n;
    vector<PII> p(n+1);
    for(int i=1;i<=n;i++)
    {
        LL x,y;
        cin>>x>>y;
        p[i]={x,y};
    }
    sort(p.begin()+1,p.end(),cmp);
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        LL a=p[i].first;
        LL b=p[i].second;
        ans+=a*(i-1)+b*(n-i);
    }
    cout<<ans<<'\n';
    return 0;
}
