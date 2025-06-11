#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10,mod = 1e9+7;

int qmi(int a,int b,int p)
{
    int res = 1;
    while(b)
    {
        if(b&1)res=a*res%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}

int f[3010][110][2];
int a[110][2];

void solve()
{
    int n,l;cin >> n >> l;
    vector<vector<int>> v;
    v.push_back({0,0});
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    for(int i = 1;i<=l;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            for(int j1 = 0;j1<=1;j1++)
            {
                if(i-a[j][j1]==0)
                {
                    f[i][j][j1] = 1;
                    if(a[j][0]==a[j][1])break;
                    continue;
                }

                for(int k = 1;k<=n;k++)
                {
                    for(int k1 = 0;k1<=1;k1++)
                    {
                        if(k==j)continue;
                        if(i-a[j][j1]>0&&a[j][j1]==a[k][k1^1])
                        {
                            f[i][j][j1] = (f[i][j][j1]+f[i-a[j][j1]][k][k1])%mod;
                        }
                        if(a[k][0]==a[k][1])break;
                    }
                }
                if(a[j][0]==a[j][1])break;
            }
        }
    }
    int ans = 0;
    for(int j = 1;j<=n;j++)
    {
        for(int j1= 0;j1<=1;j1++)
        {
            ans = (ans+f[l][j][j1])%mod;
        }
    }

    cout << ans << endl;
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
