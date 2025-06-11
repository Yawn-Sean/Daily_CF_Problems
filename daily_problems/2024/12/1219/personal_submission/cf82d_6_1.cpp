#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N =1e3+10,INF = 0x3f3f3f3f3f3f3f3f;

int a[N];
int f[N][N];

void solve()
{
    int n;cin >> n;
    memset(f,sizeof f,0x3f);
    for(int i = 1;i<=n;i++)cin >> a[i],f[i][n+1] = a[i];
    for(int i = 1;i<=n;i++)f[i][n] = max(a[i],a[n]);
    for(int i = n-2;i>=1;i--)
    {
        for(int j = n-1;j>=i+1;j--)
        {
            f[i][j] = min(f[j+1][j+2]+max(a[i],a[j]),min(f[j][j+2]+max(a[i],a[j+1]),f[i][j+2]+max(a[j],a[j+1])));
        }
    }
    int i = 1,j = 2;
    cout << f[1][2] << endl;
    while(1)
    {
        if(j==n){cout << i << ' ' << j << endl;break;}
        if(j==n+1){cout << i << endl;break;}
        if(f[i][j] == f[j+1][j+2]+max(a[i],a[j]))cout << i << ' ' << j <<endl,i = j+1,j = j+2;
        else if(f[i][j] == f[j][j+2]+max(a[i],a[j+1]))cout << i << ' ' << j+1 << endl,i = j,j=j+2;
        else if(f[i][j] == f[i][j+2]+max(a[j],a[j+1]))cout << j << ' ' << j+1 << endl,j = j+2;
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
