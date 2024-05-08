#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int mod = 998244353;
LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = (res % p) * (a % p) % p;
        a = (a % p) * (a % p) % p;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+10);
    unordered_map<int,vector<int>> mp;
    for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]].push_back(i);
    vector<PII> p;
    for(auto& [key,vt] : mp)
    {
        sort(vt.begin(),vt.end());
        p.push_back({*vt.begin(),vt.back()});
    }
    sort(p.begin(),p.end());
    vector<PII> res;
    int st=-2e9,ed=-2e9;
    for(auto h:p)
    {
        if(ed<h.first)
        {
            if(st!=-2e9) res.push_back({st,ed});
            st=h.first,ed=h.second;
        }
        else ed=max(ed,h.second);
    }
    if(st!=-2e9) res.push_back({st,ed});
    int tt = res.size();
    tt--;
    cout<<qmi(2,tt,mod)<<endl;
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
