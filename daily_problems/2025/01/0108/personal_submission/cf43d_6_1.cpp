#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    int n,m;cin >> n >> m;
    if(n==1&&m==2)
    {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 1 << ' ' << 2 << endl;
        cout << 1 << ' ' << 1 << endl;
        return ;
    }
    if(n==2&&m==1)
    {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 2 << ' ' << 1 << endl;
        cout << 1 << ' ' << 1 << endl;
        return ;
    }
    if(n==1)
    {
        cout << 1 <<endl;
        cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        for(int i = 1;i<=m;i++)cout << 1 << ' ' << i << endl;
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    if(m==1)
    {
        cout << 1 <<endl;
        cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        for(int i = 1;i<=n;i++)cout << i << ' ' << 1 << endl;
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    if(m%2==0)
    {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        int y = 1;
        while(y<=m)
        {
            for(int i = 2;i<=n;i++)
            {
                cout << i << ' ' << y << endl;
            }
            y++;
            for(int i = n;i>=2;i--)
            {
                cout << i << ' ' << y << endl;
            }
            y++;
        }
        for(int i = m;i>=1;i--)
        {
            cout << 1 << ' ' << i << endl;
        }
    }
    else if(n%2==0)
    {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        int x = 1;
        while(x<=n)
        {
            for(int i = 2;i<=m;i++)
            {
                cout << x << ' ' << i << endl;
            }
            x++;
            for(int i = m;i>=2;i--)
            {
                cout << x << ' ' << i << endl;
            }
            x++;
        }
        for(int i = n;i>=1;i--)
        {
            cout << i << ' ' << 1 << endl;
        }
    }
    else
    {
        cout  << 1 << endl;
        cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        int x = 1;
        while(x<=n)
        {
            for(int i = 1;i<=m;i++)
            {
                cout << x << ' ' << i << endl;
            }
            x++;
            if(x>n)break;
            for(int i = m;i>=1;i--)
            {
                cout << x << ' ' << i << endl;
            }
            x++;
        }
        cout << 1 << ' ' << 1 << endl;
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
