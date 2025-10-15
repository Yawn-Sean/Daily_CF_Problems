#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e7+10,modb = 4294967296,INF = 0x3f3f3f3f3f3f3f3f;

int a[N],b[N];
void solve()
{
    int n,l,r,x,y,z;
    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
    int mod = r-l+1;
    a[1] = b[1]%mod+l;
    a[2] = b[2]%mod+l;
    for(int i = 3;i<=n;i++)
    {
        b[i] = (1ull*(b[i-2]*x+b[i-1]*y+z))%modb;
        a[i] = b[i]%mod+l;
    }
    int ans = INF;
    int mi = INF,mx = -INF;
    for(int i = 1;i<=n;i++)
    {
        if(a[i]>0)
        {
            if(mi<a[i])
            ans = min(a[i]*mi,ans);
        }
        mi = min(mi,a[i]);
    }

    for(int i = n;i>=1;i--)
    {
        if(a[i]<0)
        {
            if(a[i]<mx)
                ans = min(ans,a[i]*mx);
        }
        mx = max(a[i],mx);
    }
    if(ans==INF)cout << "IMPOSSIBLE\n";
    else cout << ans << endl;
}

signed main()
{
    IOS
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
