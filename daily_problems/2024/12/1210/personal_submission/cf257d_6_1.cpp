#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

int a[N],st[N];


void solve()
{
    int n;cin >> n;
    for(int i = 1;i<=n;i++)cin >> a[i];
    int sum = a[n];
    string ans = "+";
    for(int i = n-1;i>=1;i--)
    {
        if(sum>=a[i])
        {
            ans.push_back('-');
            sum-=a[i];
        }
        else
        {
            ans.push_back('+');
            sum = (a[i]-sum);
            st[i] = 1;
        }
    }
    int now = 0;
    reverse(ans.begin(),ans.end());
    for(int i = 0;i<=n-1;i++)
    {
        if(now)
        {
            if(ans[i]=='+')ans[i]='-';
            else ans[i] = '+';
        }
        if(st[i+1]==1)now^=1;
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
