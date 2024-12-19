#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N =2e3+10;

int a[N],st[N];
pii b[N];

void solve()
{
    int n,m;cin >> n >> m;
    map<int,int> ma;

    for(int i = 1;i<=2*n;i++)cin >> a[i];
    for(int i = 1;i<=m;i++)
    {
        int x,y;cin >> x >> y;
        if(a[x]<a[y])swap(x,y);
        b[i] = {x,y};
        ma[x] = y;
        ma[y] = x;
    }
    int t;cin >> t;
    set<pii,greater<pii>> se;
    for(int i = 1;i<=2*n;i++)
    {
        if(!ma.count(i))se.insert({a[i],i});
    }
    if(t==1)
    {
        for(int i = 1;i<=m;i++)
        {
            cout << b[i].first << endl;
            int x;
            cin >> x;
        }
        while(!se.empty())
        {
            int now = (*se.begin()).second;
            se.erase(*(se.begin()));
            cout << now << endl;
            int q;cin >> q;
            se.erase({a[q],q});
        }
    }
    else
    {
        int x;
        while(cin >> x)
        {
            if(ma.count(x))cout << ma[x] << endl,ma.erase(ma[x]),ma.erase(x);
            else
            {
                se.erase({a[x],x});
                for(int i = 1;i<=m;i++)
                {
                    if(!ma.count(b[i].first))continue;
                    cout << b[i].first << endl;
                    int q;cin >> q;
                }
                while(!se.empty())
                {
                    int now = (*se.begin()).second;
                    se.erase(*se.begin());
                    cout << now << endl;
                    int q;cin >> q;
                    se.erase({a[q],q});
                }
                break;
            }
        }
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
