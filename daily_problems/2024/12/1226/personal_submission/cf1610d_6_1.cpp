#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10,p = 1e9+7;

int fac[N],a[N];

int qmi(int a,int b,int p)
{
    int res = 1;
    while(b)
    {
        if(b&1)res=a%p*(res%p)%p;
        b>>=1;
        a=a%p*a%p;
    }
    return res;
}

int C(int n,int m)
{
    return fac[n]*qmi(fac[n-m]*fac[m]%p,p-2,p)%p;
}

void solve()
{
    fac[0] = 1;
    for(int i = 1;i<=N-5;i++)fac[i] = fac[i-1]*i%p;
    map<int,int> ma;
    int n;cin >> n;
    for(int i = 1;i<=n;i++)cin >> a[i];
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        int cnt = 0,c = a[i];
        while(c%2==0)
        {
            c/=2;
            cnt++;
        }
        ma[cnt]++;
    }

    int j = ma[0];
    ans +=  (qmi(2,j,p)-1+p)%p*qmi(2,n-j,p)%p;

    ma.erase(0);
    n-=j;
    for(auto [x,y]:ma)
    {
        n-=y;
        for(int i = 2;i<=y;i+=2)
        {
            ans = (ans+C(y,i)*qmi(2,n,p)%p)%p;
        }
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
