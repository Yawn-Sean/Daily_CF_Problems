#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;
const int M = 1e5;
map<int,int> ma;
void solve()
{
    int x;cin >> x;
    for(int i = 1;i<x/i;i++)
    {
        if(x%i==0)
        {
            int a = i,b = x/i;
            if((b-a)%2==0)
            {
                int q = (b-a)/2;
                int n = b-q,m = n/q;
                if(n/m!=q)continue;
                // cout << q;
                cout << n << ' ' << m << endl;
                return;
            }
        }
    }
    if(x==0)cout << 1 << ' ' << 1 << endl;
    else 
    cout << -1 << endl;
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
