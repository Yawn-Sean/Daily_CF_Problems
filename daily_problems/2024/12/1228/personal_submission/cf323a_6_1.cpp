#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    int n;cin >> n;
    if(n&1)
    {
        cout << -1 << endl;
        return;
    }
    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j+=2)
            {
                if((k/2)&1)
                {
                    if(i&1)
                    {
                        if((j/2)&1)
                        cout << "ww";
                        else cout << "bb";
                    }
                    else
                    {
                        if((j/2)&1)
                        cout << "bb";
                        else cout << "ww";
                    }
                }
                else 
                {
                    if(i&1)
                    {
                        if((j/2)&1)
                        cout << "bb";
                        else cout << "ww";
                    }
                    else
                    {
                        if((j/2)&1)
                        cout << "ww";
                        else cout << "bb";
                    }
                }
            }
            cout << endl;
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
