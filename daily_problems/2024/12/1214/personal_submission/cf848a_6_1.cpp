#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

int qmi(int a,int b,int p)
{
    int res = 1;
    while(b)
    {
        if(b&1)res=a*res%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}

void solve()
{
    int k;cin >> k;

    int now = 'a';
    string ans;
    
    while(k)
    {
        int l = 1,r = k;
        while(l<r)
        {
            int mid = l+r+1>>1;
            if((1+mid)*mid/2>k)r = mid-1;
            else l = mid;
        }
        k-=(1+l)*l/2;
        for(int i = 1;i<=l+1;i++)ans+=now;
        now++;
    }
    if(ans.empty())ans.push_back(now);
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
