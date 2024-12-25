#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;


void solve()
{
    int n,k;cin >> n >> k;
    vector<vector<char>> g(4,vector<char>(n,'.'));
    cout << "YES\n";
    if(k&1)
    {
        int c = max((n-2-k)/2,0ll);
        for(int j = c+1;j<=c+min(k,n-2);j++)g[1][j] = '#';
        if(k>n-2)
        {
            k-=n-2;
            int l = 1,r = n-2;
            while(k)
            {
                k-=2;
                g[2][l] = g[2][r] = '#';
                l++,r--;
            }
        }

    }
    else
    {
        for(int j = 1;j<=k/2;j++)
        {
            g[1][j] = g[2][j]  = '#';
        }
    }
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<n;j++)cout << g[i][j];
        cout << '\n';
    }
}

signed main()
{
    IOS
    int tt = 1;

    while(tt--)
    {
        solve();
    }
    return 0;
}
