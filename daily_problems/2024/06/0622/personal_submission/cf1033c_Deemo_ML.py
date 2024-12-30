#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int f[N][2];

int dfs(int u,int who)
{
    if(f[u][who]>=0)
        return f[u][who];
    int res=0;
    for(auto j:g[u])
    {
        if(dfs(j,who^1)==0)
            res=1;
    }
    f[u][who]=res;
    return f[u][who];
}

int main()
{
    memset(f,-1,sizeof(f));
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j-=a[i])
        {
            if(a[j]>a[i])
                g[i].push_back(j);
        }
        for(int j=i;j<=n;j+=a[i])
        {
            if(a[j]>a[i])
                g[i].push_back(j);
        }
    }
    string ans;
    for(int i=1;i<=n;i++)
    {
        if(dfs(i,0)==1)
            ans.push_back('A');
        else
            ans.push_back('B');
    }
    cout<<ans<<'\n';
    return 0;
}
