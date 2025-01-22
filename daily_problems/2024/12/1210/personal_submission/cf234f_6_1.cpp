#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 200+10,M = 4e4+10,INF = 0x3f3f3f3f;

int h[N],f[N][M][2],sum[N];

void solve()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    int a,b;cin >> a >> b;

    for(int i = 1;i<=n;i++)cin >> h[i],sum[i]=sum[i-1]+h[i];

    memset(f,0x3f,sizeof f);
    int flag = 0;
    f[0][0][1] = 0;
    f[0][0][0] = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<=min(sum[i],a);j++)
        {
            if(sum[i]-j>b)continue;
            if(j>=h[i])f[i][j][1] = min(f[i-1][j-h[i]][1],f[i-1][j-h[i]][0]+min(h[i],h[i-1]));
            f[i][j][0] = min(f[i-1][j][0],f[i-1][j][1]+min(h[i],h[i-1]));
        }
    }
    
    int ans = INF;
    for(int i = 0;i<=min(sum[n],a);i++)
    {

        ans = min(ans,f[n][i][1]);
        ans = min(ans,f[n][i][0]);
    }
    if(ans!=INF)
    cout << ans << endl;
    else cout << -1 << endl;



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
