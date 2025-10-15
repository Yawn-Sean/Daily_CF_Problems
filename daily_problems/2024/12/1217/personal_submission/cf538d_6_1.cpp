#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    int n;cin >> n;
    vector<string> g(n+1);
    for(int i = 1;i<=n;i++)cin >> g[i],g[i] = ' ' +g[i];
    vector<pair<int,int>> oloc,xloc,dloc;
    set<pair<int,int>> ma;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(g[i][j]=='o')oloc.push_back({i,j});
            if(g[i][j]=='.')dloc.push_back({i,j});
            if(g[i][j]=='x')xloc.push_back({i,j});
        }
    }

    for(auto [x,y]:dloc)
    {
        for(auto [a,b]:oloc)
        {
            ma.insert({x-a,y-b});
        }
    }
    for(auto [x,y]:xloc)
    {
        int flag = 0;
        for(auto[a,b]:oloc)
        {
            if(ma.count({x-a,y-b})==0)flag = 1;
        }
        if(!flag){cout << "NO\n";return;}
    }
    vector<vector<char>> ans(2*n+1,vector<char>(2*n+1,'x'));
    cout << "YES\n";

    for(auto [x,y]:ma)
    {
        ans[n+x][n+y] = '.';
    }
    ans[n][n]= 'o';

    for(int i = 1;i<=2*(n-1)+1;i++)
    {
        for(int j = 1;j<=2*(n-1)+1;j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
