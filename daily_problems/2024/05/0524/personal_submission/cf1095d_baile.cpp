#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
void solve()
{
    int n;
    cin>>n;
    map<PII,int> h;
    vector<PII> e(n+10);
    for(int i=1;i<=n;i++)
    {
        int a1,a2;
        cin>>a1>>a2;
        e[i] = {a1,a2};
        h[{i,a1}] = a2;
        h[{i,a2}] = a1;
    }
    PII st = {e[1].first,e[1].second};
    int cnt = 3;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(e[1].first);
    ans.push_back(e[1].second);
    while(1)
    {
        int to = h[st];
        cnt++;
        if(to==1||to==0||cnt>n+1) break;
        ans.push_back(to);
        st = {st.second,to};
    }
    if(cnt==n+1)
    {
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
        return;
    }
    ans.clear();
    ans.push_back(1);
    ans.push_back(e[1].second);
    ans.push_back(e[1].first);
    st = {e[1].second,e[1].first};
    cnt = 3;
    while(1)
    {
        int to = h[st];
        cnt++;
        if(to==1||to==0||cnt>n+1) break;
        ans.push_back(to);
        st = {st.second,to};
    }
    if(cnt==n+1)
    {
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
        return;
    }
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
