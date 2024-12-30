#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAX32=2147483647;
const int N = 1e5+10;
int vul[N];
int dfs(vector<vector<int>>& h,int u,int fa)
{
    if(h[u].size()==1&&u!=1)
    {
        vul[u] = 1;
        return 1;
    }
    if(vul[u]) return vul[u];
    int sum = 0;
    for(int i = 0;i<h[u].size();i++)
    {
        if(h[u][i]!=fa)
            sum += dfs(h,h[u][i],u);
    }
    vul[u] = sum;
    return sum;
}
void solve()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    for(int i=0;i<=n;i++) vul[i] = 0;
    vector<vector<int>> h(n+10);
    for(int i=2;i<=n;i++)
    {
        int to;
        cin>>to;
        h[to].push_back(i);
        h[i].push_back(to);
    }
    dfs(h,1,-1);
    sort(vul+1,vul+1+n);
    for(int i=1;i<=n;i++) cout<<vul[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    while (t--)
    {
        solve();
    }
}
