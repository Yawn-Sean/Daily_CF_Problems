#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
void solve()
{
    int n;
    cin>>n;
    vector<PII> qz(n+10);
    vector<PII> hz(n+10);
    vector<PII> p(n+10);
    qz[0] = {0,1e9};
    hz[n+1] = {0,1e9};
    for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for(int i=1;i<=n;i++)
    {
        auto [l,r] = p[i];
        if(qz[i-1].first==-1) qz[i] = qz[i-1];
        else {
            qz[i] = {max(qz[i-1].first,l),min(qz[i-1].second,r)};
            if(qz[i].second<qz[i].first) qz[i] = {-1,-1};
        }
    }
    for(int i=n;i>=1;i--)
    {
        auto [l,r] = p[i];
        if(hz[i+1].first==-1) hz[i] = hz[i+1];
        else{
            hz[i] = {max(hz[i+1].first,l),min(hz[i+1].second,r)};
            if(hz[i].second<hz[i].first) hz[i] = {-1,-1};
        }
        
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        auto [l1,r1] = qz[i-1];
        auto [l2,r2] = hz[i+1];
        int r = min(r1,r2);
        int l = max(l1,l2);
        if(l1!=-1&&l2!=-1)
            ans = max(ans,max(r-l,0LL));
    }
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}
