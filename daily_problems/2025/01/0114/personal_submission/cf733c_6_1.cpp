#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10,INF = 0x3f3f3f3f3f3f3f3f;

int a[N],b[N];
int l[N],r[N];

void solve()
{
    int n;cin >> n;
    for(int i = 1;i<=n;i++)cin >> a[i];

    int m;cin >> m;
    for(int i = 1;i<=m;i++)cin >> b[i];

    int idx = 1;

    vector<pair<int,char>> ans;
    

    for(int i = 1;i<=m;i++)
    {
        int sum = 0;
        int ll = idx;
        while(idx<=n&&sum<b[i])
        {
            sum+=a[idx];
            idx++;
        }
        if(sum!=b[i])
        {
            cout << "NO\n";
            return;
        }
        l[i] = ll,r[i] = idx-1;
    }
    if(idx!=n+1)
    {
        cout << "NO\n";
        return;
    }
    int o = 0;
    for(int i = 1;i<=m;i++)
    {
        int mx = 0,mi = INF,mxli = l[i],mxri = l[i];
        int oo = 0;
        if(l[i]==r[i])continue;
        for(int j = l[i];j<=r[i];j++)
        {
            mx = max(mx,a[j]);
            mi = min(mi,a[j]);
        }
        if(mx==mi)
        {
            cout << "NO\n";
            return;
        }
        int ansi = l[i];
        for(int j = l[i];j<=r[i];j++)
        {
            if(a[j]==mx)
            {
                if(j-1>=l[i]&&a[j-1]<a[j])
                {
                    for(int k = j-1;k>=l[i];k--)
                    {
                        ans.push_back({j-o,'L'});
                        o++;
                    }
                    for(int k = j+1;k<=r[i];k++)
                    {
                        ans.push_back({j-o,'R'});
                        oo++;
                    }
                    o+=oo;
                    break;
                }
                if(j+1<=r[i]&&a[j+1]<a[j])
                {
                    for(int k = j+1;k<=r[i];k++)
                    {
                        ans.push_back({j-o,'R'});
                        oo++;
                    }
                    for(int k = j-1;k>=l[i];k--)
                    {
                        ans.push_back({j-o,'L'});
                        o++;
                    }
                    o+=oo;
                    break;
                }
            }
        }
         
    }

    cout << "YES\n";
    for(auto [x,y]:ans)
    {
        cout << x << ' ' << y << endl;
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
