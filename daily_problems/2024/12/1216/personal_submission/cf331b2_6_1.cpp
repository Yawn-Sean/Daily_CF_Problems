#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 3e5+10;

int t[N],pos[N],a[N];

void add(int i,int x)
{
    while(i<N)
    {
        t[i]+=x;
        i+=(i&-i);
    }
}

int ask(int i)
{
    int ans = 0;
    while(i)
    {
        ans+=t[i];
        i-=(i&-i);
    }
    return ans;
}

int ask(int a,int b)
{
    return abs(ask(a-1)-ask(b-1))+1;
}

void put(int i,int x)
{
    int now = ask(i)-ask(i-1);
    add(i,x-now);
}

void solve()
{
    int n;cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 1;i<n;i++)
    {
        if(pos[i]>pos[i+1])add(i,1);
    }

    int q;cin >> q;
    while(q--)
    {
        int c,x,y;cin >> c >> x >> y;
        if(c==1)
        {
            cout << ask(x,y) << endl;
        }
        else
        {
            swap(a[x],a[y]);
            swap(pos[a[x]],pos[a[y]]);
            if(a[y]+1<=n)put(a[y],(pos[a[y]]>pos[a[y]+1]));
            if(a[y]>=2)put(a[y]-1,(pos[a[y]-1]>pos[a[y]]));

            if(a[x]+1<=n)put(a[x],(pos[a[x]]>pos[a[x]+1]));
            if(a[x]>=2)put(a[x]-1,(pos[a[x]-1]>pos[a[x]]));
        }
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
