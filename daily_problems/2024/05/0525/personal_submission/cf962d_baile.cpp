#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAX32=2147483647;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+10);
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]].push_back(i);
    } 
    for(auto& [key,vt] : mp)
    {
        sort(vt.begin(),vt.end());
        for(int i=0;i+1<vt.size();i+=2)
        {
            vt[i] = -1;
            mp[key*2].push_back(vt[i+1]);
            vt[i+1] = -1;

        }
    }
    vector<int> ans(n+10);
    for(auto& [key,vt] : mp)
    {
        for(int i=0;i<vt.size();i++)
        {
            if(vt[i]!=-1)
                ans[vt[i]] = key;

        }
    }
    vector<int> aans;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) aans.push_back(ans[i]);
    }
    cout<<aans.size()<<endl;
    for(auto it : aans) cout<<it<<" ";
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
