#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

int a[N],sum[N][30];

void solve()
{
    int n,k;cin >> n >> k;
    vector<pair<int,int>> pf;
    for(int i = 2;i<=k/i;i++)
    {
        if(k%i==0)
        {
            int cnt = 0;
            while(k%i==0)
            {
                k/=i;
                cnt++;
            }
            pf.push_back({i,cnt});
        }
    }
    if(k>1)pf.push_back({k,1});
    int m = pf.size();

    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        for(int j = 0;j<m;j++)
        {
            sum[i][j] = sum[i-1][j];
            int p = pf[j].first,cnt = 0;
            while(a[i]%p==0)
            {
                a[i]/=p;
                cnt++;
            }
            sum[i][j] += cnt;
        }
    }

    auto check = [&](int mid,int i)
    {
        for(int j = 0;j<m;j++)
        {
            int cnt = sum[mid][j]-sum[i-1][j];
            if(cnt<pf[j].second)return false;
        }
        return true;
    };

    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        int l = i,r = n;
        while(l<r)
        {
            int mid = l+r>>1;
            if(check(mid,i))r = mid;
            else l = mid+1;
        }
        if(check(r,i))ans+=n-r+1;
    }
    cout << ans << endl;
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
