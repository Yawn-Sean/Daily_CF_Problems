#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define int ll
//const int mod=0?0:1e9+7
void solve()
{
     int b,d;
    string a,c;
    cin>>b>>d>>a>>c;
    int n=c.size();
    vector<int>p(n),cnt(n);
    iota(p.begin(),p.end(),0);
    for(int i=0;i<n;i++)
        {
            for(auto ch:a)
                {
                    if(ch==c[p[i]])
                    {
                        p[i]++;
                        if(p[i]==n)
                        {
                            p[i]=0;
                            cnt[i]++;
                        }
                    }
                }
        }
    int ans=0;
    int cur=0;
    while(b--)
        {
            ans+=cnt[cur];
            cur=p[cur];
        }
    ans/=d;
    cout<<ans<<'\n';
}
signed main()
{
    int t;
    t=1;
    while(t--)
    {	solve();
        }
    return 0;
}
