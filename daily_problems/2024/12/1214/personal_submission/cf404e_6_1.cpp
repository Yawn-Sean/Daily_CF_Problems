#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e6+10,M = 1e6;
int st[2*N];

void solve()
{
    string s;cin >> s;s = ' ' +s;
    int n = s.size()-1;
    int now = 0;
    st[M] = 1;
    for(int i = 1;i<n;i++)
    {
        now+=(s[i]=='R'?1:-1);
        st[now+M] = 1;
    }
    now+=(s[n]=='R'?1:-1);
    if(!st[now+M]){cout << 1 << endl;return;}

    int last = (s[n]=='R'?-1:1);

    auto check = [&](int mid)
    {
        for(int i = -n;i<=n;i++)st[i+M] = 0;
        st[M] = 1;
        int now = 0;
        int o = last*mid;
        for(int i = 1;i<n;i++)
        {
            if(s[i]=='R'&&now+1!=o)now++;
            if(s[i]=='L'&&now-1!=o)now--;
            st[now+M] = 1;
        }
        if(s[n]=='R'&&now+1!=o)now++;
        if(s[n]=='L'&&now-1!=o)now--;
        return (!st[now+M]);
    };
    int l = 1,r = n;
    while(l<r)
    {
        int mid = l+r+1>>1;
        if(check(mid))l = mid;
        else r = mid-1;
    }
    if(!check(l))cout << 0 << endl;
    else cout << l << endl;
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
