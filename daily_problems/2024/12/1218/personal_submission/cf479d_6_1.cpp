#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef pair<int,int> pii;

const int N = 2e5+10;

int a[N],n,l,x,y;

bool search(int x)
{
    for(int i = 1;i<=n;i++)
    {
        int l = i,r = n;
        while(l<r)
        {
            int mid = l+r>>1;
            if(a[mid]-a[i]>=x)r = mid;
            else l = mid+1;
        }
        if(a[r]-a[i]==x)return 1;
    }
    return 0;
}

vector<pii> find(int x)
{
    vector<pii> v;
    for(int i = 1;i<=n;i++)
    {
        int l = i,r = n;
        while(l<r)
        {
            int mid = l+r>>1;
            if(a[mid]-a[i]>=x)r = mid;
            else l = mid+1;
        }
        if(a[r]-a[i]==x)v.push_back({i,r});
    }
    return  v;
}

void solve()
{
    cin >> n >> l >> x >> y;
    for(int i = 1;i<=n;i++)cin >> a[i];
    if(search(x)&&search(y)){cout << 0 << endl;return;}
    if(search(x))
    {
        cout << 1 << endl;
        cout << y << endl;
        return;
    }
    if(search(y))
    {
        cout << 1 << endl;
        cout << x << endl;
        return;
    }
    vector<pii> v = find(x+y);
    if(v.size()>0)
    {
        cout << 1 << endl;
        cout << a[v[0].first]+x << endl;
        return;
    }
    v = find(y-x);
    int ans = 0;
    for(auto xx:v)
    {
        int i = a[xx.first],j = a[xx.second];
        if(i-x>=0){ans = i-x;break;}
        if(i+y<=l){ans = i+y;break;}
    }
    if(!ans)
    {
        cout << 2 << endl;
        cout << x << ' ' << y << endl;
    }
    else 
    {
        cout << 1 << endl;
        cout << ans << endl;
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
